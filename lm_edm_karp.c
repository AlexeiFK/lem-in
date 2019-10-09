/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_edm_karp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:28:20 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/09 22:36:44 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

int			is_es(int s, int e, int n1, int n2)
{
	if (n1 == s && n2 == (s + 1))
		return (1);
	if (n2 == s && n1 == (s + 1))
		return (1);
	if (n1 == e && n2 == (e - 1))
		return (1);
	if (n2 == e && n1 == (s - 1))
		return (1);
	return (0);
}

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

int			**fls_copy(int **src, int size)
{
	int		**tmpfls;
	int		i;

	i = 0;
	tmpfls = (int**)malloc(sizeof(int*) * size);
	if (!tmpfls)
		return (NULL);
	while (i < size)
	{
		tmpfls[i] = (int*)malloc(sizeof(int) * size);
		ft_memcpy(tmpfls[i], src[i], sizeof(int) * size);
		++i;
	}
	return (tmpfls);
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

void		arrintset(int *res, int size, int set)
{
	int 	i;

	i = 0;
	while (i < size)
	{
		res[i] = set;
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
		change_flow(t->fls, res, d.s, d.e); //		lm_print_flow(t);
		arrintset(res, size, -1);
		ret = 1;
	}
//	ft_printf("alg is over\n");
	lm_get_result_table(t->fls, tmpfls, size);
	t->r_fls = tmpfls;
//	lm_print_flow(t);
	return (ret);
}
