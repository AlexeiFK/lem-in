/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:22:04 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/04 23:03:11 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

int		*ft_newarr(int size, int set)
{
	int		*new;

	new = (int*)malloc(sizeof(int) * size);
	if (!new)
		return (NULL);
	ft_memset(new, set, size);
	return (new);
}

void	print_q(t_list *q)
{
	int		*d;

	d = (int*)(q->content);
	ft_printf("%d-", *d);
}

int		*ft_bfs(int **fls, int size, int s, int e)
{
	int		resik;
	t_list	*q;
	int		*visited;
	int		*res;
	int		id;
	int		i;

	ft_printf("bfs open, size:%d\n", size);
	resik = 0;
	if ((visited = ft_newarr(size, 0)) == NULL)
		return (NULL);
	if ((res = ft_newarr(size, INT_MAX)) == NULL)
		return (NULL);
//	q = ft_lstnew(&s, sizeof(int));
	q = NULL;
	ft_printf("res and vis malloced\n");
	ft_enqueue_int(&q, s);
	ft_printf("\nst_q:");
	ft_lstiter(q, print_q);
	visited[s] = 1;
	while (!ft_is_empty_q(q))
	{
		id = ft_dequeue_int(&q);
		ft_printf("\nid=%d", id);
		ft_printf("\n1)q:");
		ft_lstiter(q, print_q);
		if (id == e)
		{
			ft_printf("FOUNDED:%d\n", e);
			resik = e;
			break ; //
		}
		i = 0;
		ft_printf("\n");
		while (i < size)
		{
//			ft_printf("flow[%d][%d]:%d\n", id, i, fls[id][i]);
			if (fls[id][i] >= 1 && visited[i] == 0)	//posible optimization
			{
				ft_enqueue_int(&q, i);
				ft_printf("\n2)q:");
				ft_lstiter(q, print_q);
				visited[i] = 1;
			}			
			++i;
		}
	}
	if (resik != e)
		ft_printf("NO PATH\n");
	free(visited);
	return (res);
}
