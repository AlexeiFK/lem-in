/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:48:50 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/12 18:32:21 by rjeor-mo         ###   ########.fr       */
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

void	ft_error_free(char **split, char *str)
{
	split_str_free(split, str);
	ft_error_msg();
}

void	ft_error_nmsg(int num)
{
	if (num == NO_PATH)
		ft_putstr_fd("ERROR:No paths\n", 2);
	exit(0);
}
