/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_start_to_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 22:55:37 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/17 14:47:16 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

int		lm_print_special_res(t_table *t)
{
	char	*result;
	int		ant;

	ant = 1;
	if (!(result = ft_strnew(1)))
		return (-1);
	while (ant <= t->n_ants)
	{
		result = ft_free_strjoin(result,
				new_ant_path(ant, t->ns[t->id_end / 2]->name));
		if (result == NULL)
			return (-1);
		++ant;
	}
	ft_putstr(result);
	ft_putchar('\n');
	free(result);
	return (1);
}

int		is_start_to_end(t_table *t)
{
	int i;

	if ((i = t->fls[t->id_start + 1][t->id_end - 1]) == 1)
	{
		if (lm_print_special_res(t) == 1)
			return (1);
		else
			return (-1);
	}
	return (0);
}
