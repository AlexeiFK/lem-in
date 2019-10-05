/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:15:20 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/05 23:16:25 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

void	print_node(t_list *lst)
{
	t_node	*n;

	n = (t_node*)lst->content;
	ft_printf("id:%d\nname:%s\nx:%d y:%d\nis_end_start:%d\n\n\n", n->id, n->name, n->x, n->y, n->is_end_start);
}

void	print_node_arr(t_table *t)
{
	t_node	*n;
	int		i;

	i = 0;
	while (i < t->size)
	{
		n = t->ns[i];
		ft_printf("id:%d\nname:%s\nx:%d y:%d\nis_end_start:%d\n\n\n", n->id, n->name, n->x, n->y, n->is_end_start);
		i++;
	}
}

void	lm_print_table(t_table *t)
{
	int		i;
	int		j;
	int		size;

	size = t->size;
	i = 0;
	ft_printf("Number of ants:%d\nSize:%d\n", t->n_ants, size);
	ft_printf("%10s ", "");
	while (i < size)
	{
		if (t->ns[i]->is_end_start == C_START)
			ft_printf("%7s%s ", t->ns[i]->name, "(s)");
		else if (t->ns[i]->is_end_start == C_END)
			ft_printf("%7s%s ", t->ns[i]->name, "(e)");
		else
			ft_printf("%10s ", t->ns[i]->name);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < size)
	{
		j = 0;
		ft_printf("%10s ", t->ns[i]->name);
		while (j < size)
		{
			ft_printf("%10d ", t->ls[i][j]);
			++j;
		}
		ft_printf("\n");
		++i;
	}
}

void	lm_print_flow(t_table *t)
{
	int		i;
	int		j;
	int		k;
	int		size;

	size = t->size;
	i = 0;
	ft_printf("Number of ants:%d\nSize:%d\n", t->n_ants, size);
	ft_printf("%5s ", "");
	ft_printf("\n");
	i = 0;
	size *= 2;
	while (i < size)
	{
		j = 0;
//		ft_printf("%5s%s\n", t->ns[i / 2]->name, "_in");
//		ft_printf("%5s%s", t->ns[i / 2 + 1]->name, "_ot");
		if ((i % 2) == 0)
		{
			k = 0;
			while (k < size)
			{
				ft_printf("-------");
				k++;
			}
			ft_printf("\n");
		}
		while (j < size)
		{
			if ((j % 2) == 1)
				ft_printf("%5d |", t->fls[i][j]);
			else
				ft_printf("%5d ", t->fls[i][j]);
			++j;
		}
		ft_printf("\n");
		++i;
	}
}

void	lm_print_res(t_table *t)
{
	int		i;
	int		j;
	int		k;
	int		size;

	size = t->size;
	i = 0;
	ft_printf("Number of ants:%d\nSize:%d\n", t->n_ants, size);
	ft_printf("%5s ", "");
	ft_printf("\n");
	i = 0;
	size *= 2;
	while (i < size)
	{
		j = 0;
//		ft_printf("%5s%s\n", t->ns[i / 2]->name, "_in");
//		ft_printf("%5s%s", t->ns[i / 2 + 1]->name, "_ot");
		if ((i % 2) == 0)
		{
			k = 0;
			while (k < size)
			{
				ft_printf("-------");
				k++;
			}
			ft_printf("\n");
		}
		while (j < size)
		{
			if ((j % 2) == 1)
				ft_printf("%5d |", t->r_fls[i][j]);
			else
				ft_printf("%5d ", t->r_fls[i][j]);
			++j;
		}
		ft_printf("\n");
		++i;
	}
}
