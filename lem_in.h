/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:36:07 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/19 19:46:15 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

# define C_START 1
# define C_END 2
# define C_COMMENT 3
# define C_EOFF 4

/*
 ** Errors codes
*/

# define DOUBLE_START 101
# define DOUBLE_END 102
# define NO_START_END 103
# define NO_PATH 104
# define NO_END 105
# define NO_START 106
# define WRONG_LINK 107
# define READ_FAIL 108
# define FT_MALLOC_ERR 109
# define READ_FAIL_NODE 110

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
	int			**r_fls;
	int			**t_fls;
	t_list		*nl;
	t_node		**ns;
	int			size;
	int			id_start;
	int			id_end;
	char		**result;
	int			is_flag;
}				t_table;

typedef struct	s_cur_tmp
{
	int			*lens;
	int			*final_split;
	int			*splits;
	int			**final_paths;
	int			**tmp_paths;
	int			size;
	int			tmp_size;
}				t_cur_tmp;

typedef struct	s_cord
{
	int			s;
	int			e;
}				t_cord;

typedef struct	s_circ
{
	int			*buff;
	int			size;
	int			start_i;
	int			end_i;
}				t_circ;

int				**fls_copy(int **src, int size);

int				is_duplicated_node(char *name, t_list *lst);

int				is_es(int s, int e, int i, int j);
void			print_ints(int *i, int size);
void			lm_print_flow(t_table *t);
void			lm_print_res(t_table *t);
int				lm_init_flow(t_table *t);

void			split_free(char **split);
void			lm_free(t_table *t);
void			lm_free_nodes_arr(t_node **n, int size);
void			lm_free_matrix(int **m, int size);
void			lm_free_ls(char **m, int size);
void			split_str_free(char **split, char *str);
void			lm_multi_free(int *lens, int *splits, int **paths, int flow);
void			free_paths(int **paths, int size);
void			lm_free_list_strs(t_list *list);

int				lm_read(t_table *t);
int				lm_read_n_ants(t_table *t, char **split);
int				lm_read_node(t_table *t, char **split, int end_start);
int				lm_read_link(t_table *t, char **split);
void			lm_print_table(t_table *t);
int				fill_link(t_table *t, char *name1, char *name2);
int				fill_node(t_table *t, char **split, int id, int end_start);
void			lm_delete_node(void *mem, size_t size);
int				ft_lstsize(t_list *lst);
void			print_node_arr(t_table *t);
void			print_node(t_list *lst);

void			ft_error_msg(void);
void			ft_error_nmsg(int num);
void			ft_error_free(char **split, char *str, int num, t_table *t);
int				lm_isnt_error(int ret);

int				ft_strisdig(char *str);
int				split_size(char **split);
char			**is_valid_link(char **split);
int				is_valid_node(char **split);
int				number_of_ants(char **split);
int				is_comm(char **split, char *str);
int				lm_init_table(t_table *t);
void			print_ints(int *res, int size);
int				is_es(int s, int e, int n1, int n2);
void			arrintset(int *res, int size, int set);
int				*arrintcpy(int *arr, int size);

void			ft_lstadd_l(t_list **alst, t_list *n);

int				ft_is_empty_q(t_list *q);
int				ft_dequeue_int(t_list **q);
void			ft_enqueue_int(t_list **q, int id);

t_circ			*ft_init_circ(int size, int num);
void			ft_add_circ(t_circ *c, int num);
int				ft_pop_circ(t_circ *c);
int				ft_circ_is_empty(t_circ *c);

int				*ft_newarr(int size, int set);
int				*arrintcpy(int *src, int size);

int				ft_bfs(int **fls, int size, t_cord c, int *res);

int				lm_edm_karp(t_table *t);

int				lm_count_ants_by_path(int as, int ps, int *rs, int *sps);

int				lm_find_res(t_table *t);

int				lm_r_flow_to_res(t_table *t);

int				lm_path_size(int *res, int s, int e);
void			lm_close_nodes(int **ls, int *path, t_cord d);
int				lm_path_size(int *path, int s, int e);
int				**d_arr_init(int size);
void			lm_rewrite_split(t_cur_tmp *info, int flow, int *splits);
void			lm_rewrite_paths(int i, int size,
				int **tmp_paths, int **final_paths);
int				lm_print_it(t_cur_tmp *info, t_table *t, int flow, int *ret);
void			lm_print_it_last(int printed,
				int flow, t_cur_tmp *info, t_table *t);

int				lm_print_final(t_table *t, int *split, int **path, int lens);
void			lm_print_flag(int size, int flow, t_table *t, int *split);
int				is_start_to_end(t_table *t);
char			*new_ant_path(int ant, const char *name);
int				**lm_new_table(int size);

#endif
