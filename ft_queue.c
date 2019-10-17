/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:35:25 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/17 18:22:52 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include "libft.h"

t_circ	*ft_init_circ(int size, int num)
{
	t_circ *c;

	if (!(c = (t_circ*)malloc(sizeof(t_circ))))
		return (NULL);
	c->size = size;
	c->start_i = 0;
	c->end_i = 1;
	if (!(c->buff = (int*)malloc(sizeof(int) * size)))
	{
		free(c);
		return (NULL);
	}
	c->buff[0] = num;
	return (c);
}

void	ft_add_circ(t_circ *c, int num)
{
	c->buff[c->end_i] = num;
	c->end_i = (c->end_i + 1) % c->size;
}

int		ft_pop_circ(t_circ *c)
{
	int		to_ret;

	to_ret = c->buff[c->start_i];
	c->start_i = (c->start_i + 1) % c->size;
	return (to_ret);
}

int		ft_circ_is_empty(t_circ *c)
{
	return (c->start_i == c->end_i);
}
