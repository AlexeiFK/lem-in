/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:19:23 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/04 13:59:45 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

int		lm_read_n_ants(t_table *t, char **split)
{
	t->n_ants = number_of_ants(split);
	if (t->n_ants == -1)
		return (-1);
	return (1);
}

int		lm_read_node(t_table *t, char **split, int end_start)
{
	static int	id = 0;

	if (is_valid_node(split) == 1)
	{
		fill_node(t, split, id, end_start);
		++id;
	}
	else
	{
		if (lm_read_link(t, split) == 1)
			return (2);
		else
			return (-1);
	}
	return (1);
}

int		lm_read_link(t_table *t, char **split)
{
	char	**l_split;

	l_split = is_valid_link(split);
	if (l_split == NULL)
		return (-1);
	fill_link(t, l_split[0], l_split[1]);
	split_free(l_split);
	return (1);
}

int		lm_read(t_table *t)
{
	char	*str;
	char	**split;
	int		comm;
	int		comm_tmp;
	char	flag;

	comm = 0;
	comm_tmp = 0;
	flag = 0;
	while (ft_gnl(0, &str, 0) > 0)
	{
		ft_putstr(str);
		ft_putstr("\n");
		split = ft_strsplit(str, ' ');
		comm = is_comm(split, str);
		ft_printf("comm = %d\n", comm);
		if (comm == -1)
		{
			split_free(split);
			free(str);
			ft_error_msg();
		}
		if (comm == C_COMMENT)
		{
			split_free(split);
			free(str);
			if (comm_tmp == C_END || comm_tmp == C_START)
				ft_error_msg();
			continue ;
		}
		if (comm == C_END)
		{
			comm_tmp = comm;
			split_free(split);
			free(str);
			continue ;
		}
		if (comm == C_START)
		{
			comm_tmp = comm;
			split_free(split);
			free(str);
			continue ;
		}
		if (flag == 0)
		{
			ft_printf("read n_ants\n");
			if (comm_tmp == C_END || comm_tmp == C_START)
				ft_error_msg();
			//leak
			if (lm_read_n_ants(t, split) == -1)
			{
				split_free(split);
				free(str);
				ft_error_msg();
			}
			else
				flag = 1;
		}
		else if (flag == 1)
		{
			ft_printf("read nodes\n");
			if ((flag = lm_read_node(t, split, comm_tmp)) == -1)
			{
				split_free(split);
				free(str);
				ft_error_msg();
			}
			comm_tmp = 0;
		}
		else if (flag == 2)
		{
			ft_printf("read links\n");
			if (comm_tmp == C_END || comm_tmp == C_START)
				ft_error_msg();
			//leak
			if (lm_read_link(t, split) == -1)
			{
				split_free(split);
				free(str);
				ft_error_msg();
			}
		}
		split_free(split);
		free(str);
	}
	free(str);
	return (1);
}
