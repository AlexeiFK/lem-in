/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:51:34 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/17 14:54:59 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

void	lm_print_flag(int size, int flow, t_table *t, int *split)
{
	int		i;

	i = 0;
	while (i < flow && t->is_flag == 1)
	{
		ft_printf("[%d]=%d\n", i, split[i]);
		++i;
	}
	if (t->is_flag == 1)
		ft_printf("Final_res:%d\n", size - 1);
}
