/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:35:25 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/04 23:03:04 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include "libft.h"

void	ft_del_first(t_list **alst)
{
	t_list	*to_free;
	t_list	*tmp;

	if (!alst)
		return ;
	tmp = *alst;
	if (tmp->next)
	{
		to_free = tmp;
		//tmp = tmp->next;
		*alst = (*alst)->next;
		free(to_free->content);
		free(to_free);
	}
	else
	{
		if (tmp)
		{
			free(tmp->content);
			free(tmp);
			*alst = NULL;
		}
	}
}

int		ft_is_empty_q(t_list *q)
{
	if (q == NULL)
		return (1);
	return (0);
}

int		ft_dequeue_int(t_list **q)
{
	int		*ret;
	int		num;
	t_list	*tmp;

	if (!(*q))
		return (-1);
	tmp = *q;
	ret = (int*)(tmp->content);
	//ft_printf("\nret = %lld, con_size = %d", *ret, tmp->content_size);
	num = *ret;
	ft_del_first(q);
	//ft_printf("\nnum = %lld\n", num);
	return (num);
}

void	ft_enqueue_int(t_list **q, int id)
{
	t_list *new;

//	ft_printf("nnn1 **q=%p, *q=%p\nf", q, *q);
	new = ft_lstnew(&id, sizeof(int));
	if (!(*q))
	{
		(*q) = new;
		return ;
	}
//	ft_printf("nnn2\n");
	ft_lstadd_l(q, new);
//	ft_printf("nnn\n");
}
