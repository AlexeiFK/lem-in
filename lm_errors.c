/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:48:50 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/15 21:25:36 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

void	ft_error_msg(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(0);
}

void	ft_error_free(char **split, char *str, int num)
{
	split_str_free(split, str);
	ft_error_nmsg(num);
}

void	ft_error_nmsg(int num)
{
	if (num == NO_PATH)
		ft_putstr_fd("ERROR:No paths\n", 2);
	if (num == NO_END)
		ft_putstr_fd("ERROR:No end\n", 2);
	if (num == NO_START)
		ft_putstr_fd("ERROR:No start\n", 2);
	if (num == NO_START_END)
		ft_putstr_fd("ERROR:No start and end\n", 2);
	if (num == DOUBLE_START)
		ft_putstr_fd("ERROR:Double start\n", 2);
	if (num == DOUBLE_END)
		ft_putstr_fd("ERROR:Double end\n", 2);
	if (num == WRONG_LINK)
		ft_putstr_fd("ERROR:Wrong node name\n", 2);
	if (num == READ_FAIL)
		ft_putstr_fd("ERROR:Read error\n", 2);
	exit(0);
}
