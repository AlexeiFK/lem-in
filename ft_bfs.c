/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:22:04 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/14 23:40:30 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

static void	q_del(void *mem, size_t s)
{
	if (s && mem)
		free(mem);
}

static int	free_ret(int *to_free, t_list **q, int ret)
{
	if (to_free)
		free(to_free);
	if (!ft_is_empty_q(*q))
		ft_lstdel(q, q_del);
	return (ret);
}

int		*ft_newarr(int size, int set)
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

int		ft_bfs(int **fls, int size, t_cord d, int *res)
{
	int		resik;
	t_list	*q;
	int		*visited;
	int		id;
	int		i;

	resik = 0;
	if ((visited = ft_newarr(size, 0)) == NULL)
		return (-1);
	q = ft_lstnew(&(d.s), sizeof(int));
	id = -1;
	visited[d.s] = 1;
	while (!ft_is_empty_q(q))
	{
		id = ft_dequeue_int(&q);
		if (id == d.e)
			return (free_ret(visited, &q, 1));
		i = 0;
		while (i < size)
		{
			if (fls[id][i] >= 1 && visited[i] == 0)
			{
				ft_enqueue_int(&q, i);
				visited[i] = 1;
				res[i] = id;
			}	
			++i;
		}
	}
	if (resik != d.e)
		return (free_ret(visited, &q, 0));
	return (0);
}
