/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_reader2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:49:31 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/04 15:35:45 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

int		lm_read_n_ants(t_table *t, char **split)
{
	t->n_ants = number_of_ants(split);
	if (t->n_ants == -1)
		return (-1);
	return (1);
}

int		lm_read_node(t_table *t, char **split, int end_start)
{
	static int	id = 0;

	if (is_valid_node(split) == 1)
	{
		fill_node(t, split, id, end_start);
		++id;
	}
	else
	{
		if (end_start != 0)
			return (-1);
		if (lm_read_link(t, split) == 1)
			return (2);
		else
			return (-1);
	}
	return (1);
}

int		lm_read_link(t_table *t, char **split)
{
	char	**l_split;

	l_split = is_valid_link(split);
	if (l_split == NULL)
		return (-1);
	fill_link(t, l_split[0], l_split[1]);
	split_free(l_split);
	return (1);
}
