/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_unflow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 23:18:16 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/07 21:47:36 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	fill_link_res(int i, int j, char **ls, int **rf)
{
	if (i == j)
		ls[i][j] = 0;
	else
	{	
		if (rf[i * 2 + 1][j * 2] == 1)
			ls[i][j] = 1;
		else
			ls[i][j] = 0;
	}
//	if (i > j)
//		if (rf[i * 2][j * 2 + 1] == 1)
//			ls[i][j] = 1;
}

int		lm_r_flow_to_res(t_table *t)
{
	int		i;
	int		j;

	i = 0;
	while (i < t->size)
	{
		j = 0;
		while (j < t->size)
		{
			fill_link_res(i, j, t->ls, t->r_fls);
			++j;
		}
		++i;
	}
	return (1);
}
