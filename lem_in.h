/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:36:07 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/04 14:10:55 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# define C_START 1
# define C_END 2
# define C_COMMENT 3

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
	int			n_ants;
	char		**ls;
	int			**fls;
	t_list		*nl;
	t_node		**ns;
	int			size;
}				t_table;

void	split_free(char **split);
int		lm_read(t_table *t);
int		lm_read_link(t_table *t, char **split);
void	lm_print_table(t_table *t);
int		fill_link(t_table *t, char *name1, char *name2);
int		fill_node(t_table *t, char **split, int id, int end_start);
void	lm_delete_node(void *mem, size_t size);
int		ft_lstsize(t_list *lst);
void	print_node_arr(t_table *t);
void	print_node(t_list *lst);
void	ft_error_msg(void);
int		ft_strisdig(char *str);
int		split_size(char **split);
char	**is_valid_link(char **split);
int		is_valid_node(char **split);
int		number_of_ants(char **split);
int		is_comm(char **split, char *str);
int		lm_init_table(t_table *t);

#endif
