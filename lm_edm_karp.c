/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_edm_karp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:28:20 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/15 22:38:42 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"
#include "libft.h"

void		change_flow(int **fls, int *path, int s, int e)
{
	int		i;

	i = e;
	while (i != s)
	{
		if (!is_es(s, e, i, path[i]))
		{
			fls[i][path[i]] += 1;
			fls[path[i]][i] -= 1;
		}
		i = path[i];
	}
}

void		lm_get_result_table(int **fls, int **res, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (res[i][j] == 1 && fls[i][j] != 0)
				res[i][j] = 0;
			++j;
		}
		++i;
	}
}

int			lm_edm_karp(t_table *t)
{
	int		**tmpfls;
	int		*res;
	int		size;
	t_cord	d;
	int		ret;

	ret = 0;
	size = t->size * 2;
	d.s = t->id_start;
	d.e = t->id_end;
	res = ft_newarr(size, -1);
	tmpfls = fls_copy(t->t_fls, size);
	if (ft_bfs(t->fls, size, d, res))
	{
		change_flow(t->fls, res, d.s, d.e);
		arrintset(res, size, -1);
		ret = 1;
	}
	free(res);
	lm_get_result_table(t->fls, tmpfls, size);
	t->r_fls = tmpfls;
	return (ret);
}
