/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:19:23 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/30 22:17:27 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

void	fill_node(t_table *t, char **split, int id)
{
	t->ns[id]->name = ft_strdup(split[0]);
	t->ns[id]->x = ft_atoi(split[1]);
	t->ns[id]->y = ft_atoi(split[2]);
}

void	lm_init(t_table *t)
{
}

void	lm_free()
{
}

int		lm_read(t_table *t)
{
	char	*str;
	char	**split;

	while (ft_gnl(0, &str, 0) == 0)
	{
		//add valid
		//add free split
		//detect comments
		split = ft_strsplit(str);
		free(str);
	}
	free(str);
	return (1);
}
