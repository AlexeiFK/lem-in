/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:16:24 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/11 16:25:38 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

int		main(void)
{
	t_table	t;

	t.n_ants = -1;
	t.ls = NULL;
	t.fls = NULL;
	t.nl = NULL;
	t.ns = NULL;
	t.size = -1;
	t.id_start = -1;
	t.id_end = -1;
	lm_read(&t);
	lm_init_flow(&t);
	t.id_start *= 2;
	t.id_end *= 2;
	t.id_end++;
	lm_find_res(&t);
	lm_free(&t);
	return (0);
}
