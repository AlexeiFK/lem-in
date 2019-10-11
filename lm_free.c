/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:15:15 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/11 19:56:35 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

void	lm_free(t_table *t)
{
	if (t->fls)
		lm_free_matrix(t->fls, t->size * 2);
	if (t->r_fls)
		lm_free_matrix(t->r_fls, t->size * 2);
	if (t->t_fls)
		lm_free_matrix(t->t_fls, t->size * 2);
	if (t->ls)
		lm_free_ls(t->ls, t->size);
	if (t->ns)
		lm_free_nodes_arr(t->ns, t->size);
}

void	lm_free_nodes_arr(t_node **n, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(n[i]->name);
		free(n[i]);
		++i;
	}
	free(n);
}

void	lm_free_matrix(int **m, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(m[i]);
		++i;
	}
	free(m);
}

void	lm_free_ls(char **ls, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(ls[i]);
		++i;
	}
	free(ls);
}

void	split_free(char **split)
{
	int		i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	split_str_free(char **split, char *str)
{
	if (split)
		split_free(split);
	if (str)
		free(str);
}

void	lm_delete_node(void *mem, size_t size)
{
	(void)size;
	free(mem);
}
