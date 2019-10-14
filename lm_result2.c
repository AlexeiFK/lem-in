/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_result2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:47:25 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/14 22:51:22 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

void	lm_close_nodes(int **ls, int *path, t_cord d)
{
	int		i;
	int		s;
	int		e;

	s = d.s;
	e = d.e;
	i = e;
	i = path[i];
	if (i != s)
	{
		ls[i][path[i]] = 0;
		ls[path[i]][i] = 0;
	}
}

int		lm_path_size(int *path, int s, int e)
{
	int		i;
	int		c;

	c = 0;
	i = e;
	while (i != s)
	{
		i = path[i];
		++c;
	}
	return (c);
}


int		**d_arr_init(int size)
{
	int		**new;

	if (!(new = (int**)malloc(sizeof(int*) * size)))
		return (NULL);
	return (new);
}



void	lm_rewrite_split(t_cur_tmp *info, int flow, int *splits)
{
	if (info->final_split)
		free(info->final_split);
	info->final_split = arrintcpy(splits, flow);
}

void	lm_rewrite_paths(int i, int size,
		int **tmp_paths, int **final_paths)
{
	int		j;

	j = i;
	i = 0;
	while (i < j)
	{
		tmp_paths[i] = arrintcpy(final_paths[i], size);
		++i;
	}
}
