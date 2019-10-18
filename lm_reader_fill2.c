/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_reader_fill2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 21:27:46 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/18 21:29:44 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

int		is_duplicated_node(char *name, t_list *lst)
{
	t_node *node;

	while (lst)
	{
		node = (t_node*)lst->content;
		if (ft_strequ(name, node->name))
			return (1);
		lst = lst->next;
	}
	return (0);
}
