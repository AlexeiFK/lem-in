/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_flow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:03:20 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/04 17:50:21 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include <limits.h>

void	fill_flow_sqr(int i, int j, int **fl, int is_linked)
{
	int		in_i;
	int		out_i;
	int		in_j;
	int		out_j;

	in_i = i * 2;
	out_i = in_i + 1;
	in_j = j * 2;
	out_j = in_j + 1;
	if (is_linked)
	{
		fl[in_i][in_j] = 0;
		fl[out_i][out_j] = 0;
		fl[in_i][out_j] = 1;
		fl[out_i][in_j] = 1;
	}
	else
	{
		fl[in_i][in_j] = 0;
		fl[out_i][out_j] = 0;
		fl[in_i][out_j] = 0;
		fl[out_i][in_j] = 0;
	}
}

void	fill_flow_node(int i, int j, char **ls, int **fl)
{
	if (i == j)
		fill_flow_sqr(i, j, fl, 1);
	else
	{
		if (ls[i][j] == 0)
			fill_flow_sqr(i, j, fl, 0);
		else if (ls[i][j] == 1)
			fill_flow_sqr(i, j, fl, 1);
	}
}

int		**init_flow(int size)
{
	int		**new;
	int		i;

	i = 0;
	size *= 2;
	if (!(new = (int**)malloc(sizeof(int*) * size)))
		return (NULL);
	while (i < size)
	{
		if (!(new[i] = (int*)malloc(sizeof(int) * size)))
			return (NULL);
		ft_bzero(new[i], sizeof(int) * size);
		++i;
	}
	return (new);
}

int		**create_flow(char **ls, int size)
{
	int		**new;
	int		i;
	int		j;

	new = init_flow(size);
	if (!new)
		return (NULL);
	ft_printf("flow malloced\n");
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			fill_flow_node(i, j, ls, new);
			++j;
		}
		++i;
	}
	return (new);
}

int		lm_init_flow(t_table *t)
{
	t->fls = create_flow(t->ls, t->size);
	ft_printf("flow created\n");
	if (!(t->fls))
		return (-1);
	lm_print_flow(t);
	return (1);
}
