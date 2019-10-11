/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_print_final.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:21:03 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/11 23:33:50 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int		lm_print_final(t_table *t, int *split, int **paths, int flow)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = lm_path_size(paths[0], t->id_start, t->id_end) + split[0];
	ft_printf("final_res:%d\n", len);
	print_ints(split, flow);
	while (i < flow)
	{
		len = lm_path_size(paths[i], t->id_start, t->id_end);
		j = 0;
		while (j < len)
		{
			ft_printf("[%d].", i);
			++j;
		}
		ft_printf("(%d)\n", j);
		++i;
	}
	return (1);
}
