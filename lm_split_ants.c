/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_split_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:07:34 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/09 21:45:09 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		find_min_id(int *res, int size)
{
	int		i;

	i = 0;
	while ((i + 1) < size)
	{
		if (res[i] < res[i + 1])
			return (i);
		++i;
	}
	return (i);
}

int				lm_count_ants_by_path(int n_ants,
		int n_paths, int *lens, int *split)
{
	int		min;

	if (n_paths == 1)
	{
		split[0] = n_ants;
		return (1);
	}
	while (n_ants)
	{
		min = find_min_id(lens, n_paths);
		split[min] += 1;
		lens[min] += 1;
		--n_ants;
	}
	if (split[n_paths - 1] == 0)
		return (0);
	return (1);
}
