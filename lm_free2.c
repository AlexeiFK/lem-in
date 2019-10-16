/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:23:48 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/16 18:24:15 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

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
