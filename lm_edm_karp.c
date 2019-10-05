/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_edm_karp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:28:20 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/05 20:52:57 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void			print_ints(int *res, int size)
{
	int		k;

	k = 0;
	while (k < size)
	{
		ft_printf("res[%d]=%d\n", k, res[k]);
		++k;
	}
}

int			lm_edm_karp(t_table *t)
{
	int		*res;
	int		size;
	t_cord	d;

	size = t->size * 2;
	d.s = t->id_start;
	d.e = t->id_end;
	res = ft_newarr(size, -1);
	ft_bfs(t->fls, size, d, res);
	print_ints(res, size);
	return (1);
}
