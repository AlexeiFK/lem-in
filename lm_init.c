/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:14:35 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/04 13:58:54 by rjeor-mo         ###   ########.fr       */
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
		tmp = tmp->next;
	}
	ft_lstdel(&t->nl, lm_delete_node);
	t->ns = new;
	return (1);
}

int		lm_init_table(t_table *t)
{
	char	**new;
	int		size;
	int		i;

	i = 0;
	size = ft_lstsize(t->nl);
	t->size = size;
	ft_lstiter(t->nl, print_node);
	lm_list_to_array(t);
	print_node_arr(t);
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
	lm_print_table(t);
	return (1);
}
