/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:16:24 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/15 23:13:15 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

static void	main_init_table(t_table *t)
{
	t->n_ants = -1;
	t->ls = NULL;
	t->fls = NULL;
	t->nl = NULL;
	t->ns = NULL;
	t->size = -1;
	t->id_start = -1;
	t->id_end = -1;
}

static void	main_error_free(t_table *t)
{
	if (t->id_start == -1 && t->id_end == -1)
		ft_error_nmsg(NO_START_END);
	else if (t->id_start == -1)
		ft_error_nmsg(NO_START);
	else if (t->id_end == -1)
		ft_error_nmsg(NO_END);
}

static int	is_flag(int argc, char **argv)
{
	if (argc > 1)
		if (ft_strequ(argv[1], "-f"))
			return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_table	t;

	t.is_flag = is_flag(argc, argv);
	main_init_table(&t);
	if (lm_read(&t) == -1)
		ft_error_nmsg(READ_FAIL);
	main_error_free(&t);
	lm_init_flow(&t);
	t.id_start *= 2;
	t.id_end *= 2;
	t.id_end++;
	if (lm_find_res(&t) == -1)
		ft_error_nmsg(NO_PATH);
	lm_free(&t);
	return (0);
}
