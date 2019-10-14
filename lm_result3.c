/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_result3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:49:57 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/14 22:51:23 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

int		lm_print_it(t_cur_tmp *info, t_table *t, int flow, int *ret)
{
	if (info->tmp_paths)
	{
		if (info->final_split)
			lm_print_final(t, info->final_split, info->tmp_paths, flow - 1);
		else
			lm_print_final(t, info->splits, info->tmp_paths, flow - 1);
	}
	else
	{
		if (info->final_split)
			lm_print_final(t, info->final_split, info->final_paths, flow - 1);
		else
			lm_print_final(t, info->splits, info->final_paths, flow - 1);
	}
	*ret = 0;
	return (1);
}

void	lm_print_it_last(int printed,
		int flow, t_cur_tmp *info, t_table *t)
{
	if (!printed)
	{
		if (info->final_split)
			lm_print_final(t, info->final_split, info->tmp_paths, flow - 1);
		else
			lm_print_final(t, info->splits, info->tmp_paths, flow - 1);
	}
}


int		lm_isnt_error(int ret)
{
	if (ret == -1)
	{
		ft_error_nmsg(NO_PATH);
		return (-1);
	}
	return (1);
}
