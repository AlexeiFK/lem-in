/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:48:50 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/16 20:03:46 by rjeor-mo         ###   ########.fr       */
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

void	ft_error_free(char **split,
		char *str, int num, t_table *t)
{
	split_str_free(split, str);
	ft_gnl(0, NULL, 1);
	lm_free(t);
	if (num == READ_FAIL_NODE)
	{
		lm_free_list_strs(t->nl);
		ft_lstdel(&t->nl, lm_delete_node);
	}
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
	if (num == READ_FAIL || num == READ_FAIL_NODE)
		ft_putstr_fd("ERROR:Read error\n", 2);
	exit(0);
}
