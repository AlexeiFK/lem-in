/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_edm_karp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:28:20 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/05 22:59:58 by rjeor-mo         ###   ########.fr       */
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

//	fls = NULL;	//
	i = e;
	while (i != s)
	{
		ft_printf("(e:%ds:%d)%d->%d\n", e, s, i, path[i]);
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
	tmpfls = ft_memalloc(sizeof(int*) * size);
	if (!tmpfls)
		return (NULL);
	while (i < size)
	{
		tmpfls[i] = ft_memalloc(sizeof(int) * size);
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

int			lm_edm_karp(t_table *t)
{
	int		**tmpfls;
	int		*res;
	int		size;
	t_cord	d;

	size = t->size * 2;
	d.s = t->id_start;
	d.e = t->id_end;
	res = ft_newarr(size, -1);
	tmpfls = fls_copy(t->fls, size);
	while (ft_bfs(t->fls, size, d, res))
	{
		ft_printf("founded path:\n");
		print_ints(res, size);
		change_flow(t->fls, res, d.s, d.e);
		lm_print_flow(t);
		ft_memset(res, -1, size * sizeof(int));
	}
	ft_printf("alg is over\n");
	ft_printf("New table:\n");
	lm_print_flow(t);
	ft_printf("Old table:\n");
	lm_get_result_table(t->fls, tmpfls, size);
	t->fls = tmpfls;
	while (ft_bfs(t->fls, size, d, res))
	{
		ft_printf("founded path:\n");
		print_ints(res, size);
		change_flow(t->fls, res, d.s, d.e);
		lm_print_flow(t);
		ft_memset(res, -1, size * sizeof(int));
	}
	lm_print_flow(t);
	return (1);
}
