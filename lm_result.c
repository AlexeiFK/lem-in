/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_result.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 21:01:07 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/07 22:32:56 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (i != s)
	{
//		ft_printf("(e:%ds:%d)%d->%d\n", e, s, i, path[i]);
		if (!is_es(s, e, i, path[i]))
		{
			ls[i][path[i]] = 0;
			ls[path[i]][i] = 0;
		}
		i = path[i];
	}
}

int		lm_find_res(t_table *t)
{
	t_cord	d;
	int		*res;
	int		num;

	num = 0;
	d.e = t->id_end;
	d.s = t->id_start;
//	return ((int)t);
//	ft_bfs(t->fls, t->size * 2, t->id_start, t->id_end);
	lm_edm_karp(t);
//	lm_print_res(t);
	lm_r_flow_to_res(t);
//	lm_print_table(t);
	t->size *= 2;//
	res = ft_newarr(t->size, -1);
	ft_printf("From: %d to %d\n", d.s, d.e);
	while (ft_bfs(t->r_fls, t->size, d, res))
	{
		num++;
		ft_printf("founded path:%d\n", num);
//		print_ints(res, t->size);
		lm_close_nodes(t->r_fls, res, d);
		//change_flow(t->fls, res, d.s, d.e);
		//--n_ants;
		//lm_print_flow(t);
		ft_memset(res, -1, t->size * sizeof(int));
	}
	return (1);
}
