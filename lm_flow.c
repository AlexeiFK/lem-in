/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_flow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:03:20 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/09 21:57:33 by rjeor-mo         ###   ########.fr       */
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
	if (is_linked == 2)
	{
		fl[in_i][out_j] = 1;
		fl[out_i][in_j] = 1;
	}
	else if (is_linked == 1)
		fl[in_i][out_j] = 1;
	else if (is_linked == 0)
		fl[out_i][in_j] = 1;
	else if (is_linked == 100)
	{							//TODO replace with INTMAX
		fl[in_i][out_j] = 100;
		fl[out_i][in_j] = 100;
	}
}

void	fill_flow_node(int i, int j, char **ls, int **fl)
{
	if (i == j)
		fill_flow_sqr(i, j, fl, 2);
	else if (i < j)
	{
		if (ls[i][j] == 1)
			fill_flow_sqr(i, j, fl, 0);
	}
	else if (i > j)
	{
		if (ls[i][j] == 1)
			fill_flow_sqr(i, j, fl, 0);
	}
}

int		**init_flow(int size)
{
	int		**new;
	int		i;
	int		j;

	i = 0;
	size *= 2;
	if (!(new = (int**)malloc(sizeof(int*) * size)))
		return (NULL);
	while (i < size)
	{
		if (!(new[i] = (int*)malloc(sizeof(int) * size)))
			return (NULL);
		j = 0;
		while (j < size)
		{
			new[i][j] = 0;
			++j;
		}
		++i;
	}
	return (new);
}

int		**create_flow(char **ls, int size, int start, int end)
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
	fill_flow_sqr(start, start, new, 100);///TODO replace with INT_MAX
	fill_flow_sqr(end, end, new, 100);///TODO replace with INT_MAX
	return (new);
}

int		lm_init_flow(t_table *t)
{
	t->fls = create_flow(t->ls, t->size,
			t->id_start, t->id_end);
	ft_printf("flow created\n");
	if (!(t->fls))
		return (-1);
//	lm_print_flow(t);
	return (1);
}
