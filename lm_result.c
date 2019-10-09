/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_result.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 21:01:07 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/09 22:38:48 by rjeor-mo         ###   ########.fr       */
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
		i = path[i];
		++c;
	}
	return ((c - 1) / 2);
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

int		lm_find_best_flow(t_table *t)
{
	t_cord	d;
	int		**tmp;
	int		*res;
	int		*lens;
	int		*splits;
	int		num;
	int		i;

	num = 0;
	d.e = t->id_end;
	d.s = t->id_start;
	tmp = fls_copy(t->fls, t->size * 2);
	t->t_fls = tmp;
	while (1)
	{
		++num;
		if (lm_edm_karp(t) == 0)
			break ;
		i = 0;
		lens = ft_newarr(num, -1);
		splits = ft_newarr(num, 0);
		res = ft_newarr(t->size * 2, -1);
		// do copy r_fls
		while (ft_bfs(t->r_fls, t->size * 2, d, res))
		{
			ft_printf("founded path:%d(len:%d)\n", num, lm_path_size(res, d.s, d.e));
			lens[i] = lm_path_size(res, d.s, d.e);
			++i;
			lm_close_nodes(t->r_fls, res, d);
			ft_memset(res, -1, t->size * 2 * sizeof(int));
		}
		if (lm_count_ants_by_path(t->n_ants, num, lens, splits) == 0)
		{
			print_ints(splits, num);
			free(lens);
			free(splits);
			break ;
		}
		print_ints(splits, num);
		t->r_fls = tmp;
	//	t->fls = tmp;
		free(lens);
		free(splits);
	}
	return (1);
}

