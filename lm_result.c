/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_result.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 21:01:07 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/17 20:05:54 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

int		lm_do_bfs(t_table *t, int flow, int *lens, int **final_paths)
{
	int		i;
	t_cord	d;
	int		*res;

	i = 0;
	d.e = t->id_end;
	d.s = t->id_start;
	res = ft_newarr(t->size * 2, -1);
	while (ft_bfs(t->r_fls, t->size * 2, d, res) && (i <= flow))
	{
		lens[i] = lm_path_size(res, d.s, d.e);
		final_paths[i] = arrintcpy(res, t->size * 2);
		++i;
		lm_close_nodes(t->r_fls, res, d);
		arrintset(res, t->size * 2, -1);
	}
	free(res);
	return (i);
}

void	lm_info_init(t_cur_tmp *info, int *flow, int *ret, int *printed)
{
	*printed = 0;
	info->tmp_size = INT_MAX;
	info->tmp_paths = NULL;
	info->final_split = NULL;
	info->size = INT_MAX - 1;
	*flow = 1;
	*ret = -1;
}

int		lm_calculate_info(t_cur_tmp *info, t_table *t, int flow, int *i)
{
	int		ret;

	info->tmp_size = info->size;
	info->lens = ft_newarr(flow, -1);
	info->splits = ft_newarr(flow, 0);
	info->final_paths = d_arr_init(flow);
	*i = lm_do_bfs(t, flow, info->lens, info->final_paths);
	ret = lm_count_ants_by_path(t->n_ants, flow, info->lens, info->splits);
	info->size = (lm_path_size(info->final_paths[0],
				t->id_start, t->id_end) - 1) / 2 + info->splits[0];
	return (ret);
}

int		lm_find_res(t_table *t)
{
	t_cur_tmp	inf;
	int			flow;
	int			i;
	int			r;
	int			printed;

	lm_info_init(&inf, &flow, &r, &printed);
	t->t_fls = fls_copy(t->fls, t->size * 2);
	while (lm_edm_karp(t) && r != 0 && inf.tmp_size >= inf.size)
	{
		r = lm_calculate_info(&inf, t, flow, &i);
		if ((r == 0 && inf.tmp_size == inf.size) || (inf.tmp_size < inf.size))
			printed = lm_print_it(&inf, t, flow, &r);
		else
			lm_rewrite_split(&inf, flow, inf.splits);
		free_paths(inf.tmp_paths, flow - 1);
		inf.tmp_paths = d_arr_init(flow);
		lm_rewrite_paths(i, t->size * 2, inf.tmp_paths, inf.final_paths);
		lm_free_matrix(t->r_fls, t->size * 2);
		lm_multi_free(inf.lens, inf.splits, inf.final_paths, flow);
		++flow;
	}
	lm_print_it_last(printed, flow, &inf, t);
	lm_multi_free(inf.final_split, NULL, inf.tmp_paths, flow - 1);
	return (lm_isnt_error(r));
}
