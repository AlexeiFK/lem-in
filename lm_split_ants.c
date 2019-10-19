/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_split_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:07:34 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/19 22:50:43 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		normalize_lens(int *lens, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		lens[i] = (lens[i] - 1) / 2;
		++i;
	}
}

static int		find_min_id(int *res, int size)
{
	int		i;
	int		id;

	id = 0;
	i = 0;
	while (i < size)
	{
		if (res[id] > res[i])
			id = i;
		++i;
	}
	return (id);
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
	normalize_lens(lens, n_paths);
	while (n_ants)
	{
		min = find_min_id(lens, n_paths);
		split[min] += 1;
		lens[min] += 1;
		--n_ants;
	}
	if (split[n_paths - 1] == 0 && split[n_paths - 2] == 0)
		return (0);
	return (1);
}
