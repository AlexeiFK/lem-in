/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_result.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 21:01:07 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/05 20:48:42 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int		lm_find_res(t_table *t)
{
//	return ((int)t);
//	ft_bfs(t->fls, t->size * 2, t->id_start, t->id_end);
	lm_edm_karp(t);
	return (1);
}
