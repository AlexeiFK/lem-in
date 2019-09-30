/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:36:07 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/30 22:17:29 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct	s_node
{
	int			id;
	char		*name;
	int			x;
	int			y;
	char		is_end_start;
}				t_node;

typedef struct	s_table
{
	char		**ls;
	int			**fls;
	t_node		**ns;
}				t_table;

#endif
