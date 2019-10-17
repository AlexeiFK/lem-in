/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:22:04 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/17 20:45:52 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

static int	free_ret(t_circ *c, int ret)
{
	if (c)
	{
		free(c->buff);
		free(c);
	}
	return (ret);
}

int			*ft_newarr(int size, int set)
{
	int		*new;
	int		i;

	i = 0;
	new = NULL;
	if (!(new = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	while (i < size)
	{
		new[i] = set;
		++i;
	}
	return (new);
}

int			add_not_visited(int id, t_circ *c, int *res, int i)
{
	ft_add_circ(c, i);
	res[i] = id;
	return (1);
}

int			ft_bfs(int **fls, int size, t_cord d, int *res)
{
	int		id;
	int		i;
	t_circ	*c;

	if (!(c = ft_init_circ(size + 1, d.s)))
		return (-1);
	id = -1;
	while (!ft_circ_is_empty(c))
	{
		id = ft_pop_circ(c);
		if (id == d.e)
			return (free_ret(c, 1));
		i = 0;
		while (i < size)
		{
			if (fls[id][i] >= 1 && res[i] == -1)
			{
				ft_add_circ(c, i);
				res[i] = id;
			}
			++i;
		}
	}
	return (free_ret(c, 0));
}
