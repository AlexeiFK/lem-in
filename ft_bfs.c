/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:22:04 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/11 22:00:26 by rjeor-mo         ###   ########.fr       */
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
//	ft_memset(new, set, size * sizeof(int));
	return (new);
}

void	print_q(t_list *q)
{
	int		*d;

	d = (int*)(q->content);
	ft_printf("%d-", *d);
}

int		ft_bfs(int **fls, int size, t_cord d, int *res)
{
	int		resik;
	t_list	*q;
	int		*visited;
	int		id;
	int		i;

//	ft_printf("bfs open, size:%d\n", size);
	resik = 0;
	q = NULL;
	i = 0;
	if ((visited = ft_newarr(size, 0)) == NULL)
		return (-1);
	q = ft_lstnew(&(d.s), sizeof(int));
	id = -1;
//	ft_printf("res and vis malloced\n");
//	ft_enqueue_int(&q, d.s); // TODO circular queue
//	ft_printf("\nst_q:");
//	ft_lstiter(q, print_q);
	visited[d.s] = 1;
//	ft_printf("Map_size:%dStart:\n", size);
	while (!ft_is_empty_q(q))
	{
		id = ft_dequeue_int(&q);
//		ft_printf("\nid=%d", id);
//		ft_printf("\n1)q:");
//		ft_lstiter(q, print_q);
		if (id == d.e)
		{
//			ft_printf("End\n");
			return (free_ret(visited, &q, 1));
		}
		i = 0;
//		ft_printf("\n");
		while (i < size)
		{
			if (fls[id][i] >= 1 && visited[i] == 0)	//posible optimization
			{
				ft_enqueue_int(&q, i);
//				ft_printf("\n2)q:");
//				ft_lstiter(q, print_q);
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
