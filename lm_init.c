/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:14:35 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/19 19:04:57 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

int		lm_list_to_array(t_table *t)
{
	t_node	**new;
	t_list	*tmp;
	t_node	*n;

	tmp = t->nl;
	if ((new = (t_node**)malloc(sizeof(t_node*) * t->size)) == NULL)
		return (-1);
	while (tmp)
	{
		n = (t_node*)tmp->content;
		if (!(new[n->id] = malloc(tmp->content_size)))
			return (-1);
		ft_memcpy(new[n->id], tmp->content, tmp->content_size);
		new[n->id]->name = ft_strdup(n->name);
		free(n->name);
		tmp = tmp->next;
	}
	ft_lstdel(&t->nl, lm_delete_node);
	t->ns = new;
	return (1);
}

int		**lm_new_table(int size)
{
	int		i;
	int		**new;

	i = 0;
	if ((new = (int**)malloc(sizeof(int*) * size)) == NULL)
		return (NULL);
	while (i < size)
	{
		if ((new[i] = (int*)malloc(sizeof(int) * size)) == NULL)
			return (NULL);
		++i;
	}
	return (new);
}

int		lm_init_table(t_table *t)
{
	char	**new;
	int		size;
	int		i;

	i = 0;
	size = ft_lstsize(t->nl);
	t->size = size;
	lm_list_to_array(t);
	t->nl = NULL;
	if ((new = (char**)malloc(sizeof(char*) * size)) == NULL)
		return (-1);
	while (i < size)
	{
		if ((new[i] = (char*)malloc(sizeof(char) * size)) == NULL)
			return (-1);
		ft_bzero(new[i], size);
		++i;
	}
	t->ls = new;
	return (1);
}
