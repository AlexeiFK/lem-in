/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:52:16 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/04 12:49:13 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lem_in.h"

int		ft_strisdig(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (ft_isdigit(str[i]) == 0 && str[i] != '-')
		return (0);
	if (str[i] == '-' && str[i + 1] == '\0')
		return (0);
	i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		if (i >= 12)
			return (0);
		i++;
	}
	return (1);
}

int		split_size(char **split)
{
	int		i;

	i = 0;
	while (split[i] != NULL)
		i++;
	return (i);
}

char	**is_valid_link(char **split)
{
	char	**link_split;

	if (split_size(split) != 1)
		return (NULL);
	link_split = ft_strsplit(split[0], '-');
	if (split_size(link_split) != 2)
	{
		split_free(link_split);
		return (NULL);
	}
	return (link_split);
}

int		is_valid_node(char **split)
{
	long long int	x;
	long long int	y;

	x = 0;
	y = 0;
	if (split_size(split) != 3)
		return (-1);
	else
	{
		if (split[0][0] == 'L')
			return (-1);
		if (ft_strisdig(split[1]) == 0)
			return (-1);
		if (ft_strisdig(split[2]) == 0)
			return (-1);
		x = ft_atoll(split[1]);
		y = ft_atoll(split[2]);
		if (x > INT_MAX || x < INT_MIN)
			return (-1);
		if (y > INT_MAX || y < INT_MIN)
			return (-1);
	}
	return (1);
}

int		number_of_ants(char **split)
{
	long long int	n;

	n = 0;
	if (split_size(split) != 1)
		return (-1);
	else
	{
		if (ft_strisdig(split[0]) == 0)
			return (-1);
		n = ft_atoll(split[0]);
		if (n > INT_MAX || n < INT_MIN)
			return (-1);
	}
	return (n);
}
