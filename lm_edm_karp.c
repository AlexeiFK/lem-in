/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_edm_karp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:28:20 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/19 19:07:05 by rjeor-mo         ###   ########.fr       */
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

void		lm_refresh_table(int **r_fls, int **t_fls, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			r_fls[i][j] = t_fls[i][j];
			++j;
		}
		++i;
	}
}

void		lm_get_result_table_(int **fls, int **res, int **orig, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (orig[i][j] == 1 && fls[i][j] != 0)
				res[i][j] = 0;
			else
				res[i][j] = orig[i][j];
			++j;
		}
		++i;
	}
}

int			lm_edm_karp(t_table *t)
{
	int		*res;
	int		size;
	t_cord	d;
	int		ret;

	ret = 0;
	size = t->size * 2;
	d.s = t->id_start;
	d.e = t->id_end;
	res = ft_newarr(size, -1);
	if (ft_bfs(t->fls, size, d, res))
	{
		change_flow(t->fls, res, d.s, d.e);
		arrintset(res, size, -1);
		ret = 1;
	}
	free(res);
	lm_get_result_table_(t->fls, t->r_fls, t->t_fls, size);
	return (ret);
}
