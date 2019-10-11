/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_result.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 21:01:07 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/11 22:33:26 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

void	lm_close_nodes(int **ls, int *path, t_cord d)
{
	int		i;
	int		s;
	int		e;

	s = d.s;
	e = d.e;
	i = e;
	i = path[i];
	if (i != s)
	{
//		ft_printf("(e:%ds:%d)%d->%d\n", e, s, i, path[i]);
//		if (!is_es(s, e, i, path[i]))
//		{
			ls[i][path[i]] = 0;
			ls[path[i]][i] = 0;
//		}
		i = path[i];
	}
}

int		lm_path_size(int *path, int s, int e)
{
	int		i;
	int		c;

	c = 0;
	i = e;
	while (i != s)
	{
//		ft_printf("(e:%ds:%d)%d->%d\n", e, s, i, path[i]);
		i = path[i];
		++c;
	}
	return (c);
}

int		lm_find_res(t_table *t)
{
//	t_cord	d;
//	int		*res;
//	int		num;

	lm_find_best_flow(t);
	return (1);
	/*
	num = 0;
	d.e = t->id_end;
	d.s = t->id_start;
//	return ((int)t);
//	ft_bfs(t->fls, t->size * 2, t->id_start, t->id_end);
	t->t_fls = fls_copy(t->fls, t->size * 2);
	lm_edm_karp(t);
	lm_edm_karp(t);
	lm_edm_karp(t);
	lm_edm_karp(t);
//	lm_edm_karp(t);
//	lm_print_res(t);
	lm_r_flow_to_res(t);
//	lm_print_table(t);
	t->size *= 2;//
	res = ft_newarr(t->size, -1);
	ft_printf("From: %d to %d\n", d.s, d.e);
	while (ft_bfs(t->r_fls, t->size, d, res))
	{
		num++;
		ft_printf("founded path:%d(len:%d)\n", num, lm_path_size(res, d.s, d.e));
//		print_ints(res, t->size);
		lm_close_nodes(t->r_fls, res, d);
	//	lm_count_ants_by_path(t->n_ants, );
		//change_flow(t->fls, res, d.s, d.e);
		//--n_ants;
		//lm_print_flow(t);
		ft_memset(res, -1, t->size * sizeof(int));
	}
	return (1);
	*/
}

void	lm_fill_lens()
{
}

int		**d_arr_init(int size)
{
	int		**new;

	if (!(new = (int**)malloc(sizeof(int*) * size)))
		return (NULL);
	return (new);
}

void	free_paths(int **paths, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (paths[i])
			free(paths[i]);
		++i;
	}
	free(paths);
}

int		lm_find_best_flow(t_table *t)
{
	t_cord	d;
	int		**tmp;
	int		*res;
	int		*lens;
	int		*final_split;
	int		**tmp_paths;
	int		**final_paths;
	int		*splits;
	int		flow;
	int		i;
	int		j;
	int		ret;

	tmp_paths = NULL;
	final_split = NULL;
	flow = 1;
	d.e = t->id_end;
	d.s = t->id_start;
	tmp = fls_copy(t->fls, t->size * 2);
	t->t_fls = tmp;
	res = ft_newarr(t->size * 2, -1);
	ret = -1;
	while (lm_edm_karp(t) && ret != 0)
	{
		i = 0;
		lens = ft_newarr(flow, -1);
		splits = ft_newarr(flow, 0);
		final_paths = d_arr_init(flow);
		while (ft_bfs(t->r_fls, t->size * 2, d, res) && (i <= flow))
		{
			ft_printf("founded path:%d(len:%d)\n", flow, lm_path_size(res, d.s, d.e));
			lens[i] = lm_path_size(res, d.s, d.e);
			final_paths[i] = arrintcpy(res, t->size * 2);
			++i;
			lm_close_nodes(t->r_fls, res, d);
		//	ft_memset(res, -1, t->size * 2 * sizeof(int)); // arrayinit add TODO
		}
		ret = lm_count_ants_by_path(t->n_ants, flow, lens, splits);
		if (ret == 0)
		{
			if (tmp_paths)
			{
				if (final_split)
					lm_print_final(t, final_split, tmp_paths, flow - 1);
				else
					lm_print_final(t, splits, tmp_paths, flow - 1);
			}
			else
			{
				if (final_split)
					lm_print_final(t, final_split, final_paths, flow - 1);
				else
					lm_print_final(t, splits, final_paths, flow - 1);
			}
		}
		else
		{
			print_ints(splits, flow);
			if (final_split)
			{
				free(final_split);
			}
			final_split = arrintcpy(splits, flow);
		}
		if (tmp_paths)
			free_paths(tmp_paths, flow - 1);
		tmp_paths = d_arr_init(flow);
		j = i;
		i = 0;
		while (i < j)
		{
			tmp_paths[i] = arrintcpy(final_paths[i], t->size * 2);
			++i;
		}
		lm_free_matrix(t->r_fls, t->size * 2);
		free_paths(final_paths, flow);
//		t->r_fls = tmp;
	//	t->fls = tmp;
///		free_paths(final_paths, flow);
//		free(final_split);
		free(lens);
		free(splits);
		++flow;
	}
	if (final_split)
		free(final_split);
	if (tmp_paths)
		free_paths(tmp_paths, flow - 1);
	free(res);
	return (1);
}
