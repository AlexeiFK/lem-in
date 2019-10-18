/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_reader_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:59:26 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/18 21:28:42 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

int		ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		++i;
	}
	return (i);
}

int		fill_node(t_table *t, char **split, int id, int end_start)
{
	t_list	*nlist;
	t_node	*new;

	if (is_duplicated_node(split[0], t->nl))
		return (-1);
	if ((new = (t_node*)malloc(sizeof(t_node))) == NULL)
		return (-1);
	new->id = id;
	new->name = ft_strdup(split[0]);
	new->x = ft_atoi(split[1]);
	new->y = ft_atoi(split[2]);
	new->is_end_start = end_start;
	if (end_start == C_START)
		t->id_start = id;
	if (end_start == C_END)
		t->id_end = id;
	if ((nlist = ft_lstnew(new, sizeof(t_node))) == NULL)
		return (-1);
	free(new);
	ft_lstadd(&t->nl, nlist);
	return (1);
}

int		find_id(t_table *t, const char *name)
{
	int		i;

	i = 0;
	while (i < t->size)
	{
		if (ft_strequ(name, t->ns[i]->name))
			return (i);
		i++;
	}
	return (-1);
}

void	set_link(t_table *t, int id1, int id2)
{
	t->ls[id1][id2] = 1;
	t->ls[id2][id1] = 1;
}

int		fill_link(t_table *t, char *name1, char *name2)
{
	static int	first = 1;
	int			id1;
	int			id2;

	if (first)
	{
		lm_init_table(t);
		first = 0;
	}
	id1 = find_id(t, name1);
	id2 = find_id(t, name2);
	if (id1 == -1 || id2 == -1)
		return (-1);
	set_link(t, id1, id2);
	return (1);
}
