/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_result_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:23:23 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/14 22:51:17 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

void	lm_multi_free(int *lens, int *splits, int **paths, int flow)
{
	if (lens)
		free(lens);
	if (splits)
		free(splits);
	free_paths(paths, flow);
}

void	free_paths(int **paths, int size)
{
	int		i;

	if (!paths)
		return ;
	i = 0;
	while (i < size)
	{
		if (paths[i])
			free(paths[i]);
		++i;
	}
	free(paths);
}
