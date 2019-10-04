/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:15:15 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/04 14:55:36 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

/*
void	lm_free(t_table *t)
{
	(void*)(t);
}
*/

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
	size = 0;
	free(mem);
}
