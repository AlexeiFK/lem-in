/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_valid_comm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:48:19 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/20 18:42:43 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_comment(char *str)
{
	if (str[0] == '#')
		return (C_COMMENT);
	else
		return (0);
}

int		is_comm(char **split, char *str)
{
	static int	st_flag = 0;
	static int	en_flag = 0;

	if (split_size(split) != 1)
		return (is_comment(str));
	if (ft_strequ(str, "##start") && (st_flag == 0))
	{
		st_flag = 1;
		return (C_START);
	}
	if (ft_strequ(str, "##start") && (st_flag == 1))
		return (-1);
	if (ft_strequ(str, "##end") && (en_flag == 0))
	{
		en_flag = 1;
		return (C_END);
	}
	if (ft_strequ(str, "##end") && (en_flag == 1))
		return (-1);
	return (is_comment(str));
}
