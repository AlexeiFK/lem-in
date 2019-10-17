/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:19:23 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/17 22:10:46 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

int		choose_read(t_table *t, int *flag, char **split, int *comm_tmp)
{
	if ((*flag) == 0)
	{
		if (((*comm_tmp) == C_END) || ((*comm_tmp) == C_START))
			return (-1);
		if (lm_read_n_ants(t, split) == -1)
			return (-1);
		else
			(*flag) = 1;
	}
	else if ((*flag) == 1)
	{
		if (((*flag) = lm_read_node(t, split, (*comm_tmp))) == -1)
			return (-1);
		(*comm_tmp) = 0;
	}
	else if ((*flag) == 2)
	{
		if ((*comm_tmp) == C_END || (*comm_tmp) == C_START)
			return (-1);
		if (lm_read_link(t, split) == -1)
			return (-1);
	}
	return (0);
}

int		comm_detect(char **split, char *str, int *comm_tmp, t_table *t)
{
	int		comm;

	comm = is_comm(split, str);
	if (comm == -1)
		ft_error_free(split, str, READ_FAIL_NODE, t);
	if (comm == C_COMMENT)
	{
		if (((*comm_tmp) == C_END) || ((*comm_tmp) == C_START))
			ft_error_free(split, str, READ_FAIL_NODE, t);
		split_str_free(split, str);
		return (1);
	}
	if (comm == C_END)
	{
		split_str_free(split, str);
		(*comm_tmp) = comm;
		return (1);
	}
	if (comm == C_START)
	{
		split_str_free(split, str);
		(*comm_tmp) = comm;
		return (1);
	}
	return (0);
}

int		lm_read(t_table *t)
{
	char	*str;
	char	**split;
	int		comm_tmp;
	int		flag;
	int		error;

	comm_tmp = 0;
	flag = 0;
	str = NULL;
	while ((error = ft_gnl(0, &str, 0)) > 0)
	{
		ft_putstr(str);
		ft_putchar('\n');
		split = ft_strsplit(str, ' ');
		if (comm_detect(split, str, &comm_tmp, t))
			continue ;
		if (choose_read(t, &flag, split, &comm_tmp) == -1)
			ft_error_free(split, str, READ_FAIL, t);
		split_str_free(split, str);
	}
	free(str);
	if (error == -1)
		return (-1);
	return (1);
}
