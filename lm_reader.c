/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:19:23 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/03 23:15:46 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

int		ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		++i;
	}
	return (i);
}

void	print_node(t_list *lst)
{
	t_node	*n;
	n = (t_node*)lst->content;
	ft_printf("id:%d\nname:%s\nx:%d y:%d\nis_end_start:%d\n\n\n", n->id, n->name, n->x, n->y, n->is_end_start);
}

int		fill_node(t_table *t, char **split, int id, int end_start)
{
	t_list	*nlist;
	t_node	*new;

	if ((new = (t_node*)malloc(sizeof(t_node))) == NULL)
		return (-1);
	new->id = id;
	new->name = ft_strdup(split[0]);
	new->x = ft_atoi(split[1]);
	new->y = ft_atoi(split[2]);
	new->is_end_start = end_start;
	if ((nlist = ft_lstnew(new, sizeof(t_node))) == NULL)
		return (-1);
	print_node(nlist);
	ft_lstadd(&t->nl, nlist);
	return (1);
}

int		fill_link(t_table *t, char *name1, char *name2)
{
	static int	first = 1;

	if (first)
	{
		lm_init_table(t);
		(void)name1;
		(void)name2;
		first = 0;
	}
	return (1);
}

void	lm_print_table(t_table *t)
{
	int		i;
	int		j;
	int		size;

	size = t->size;
	i = 0;
	ft_printf("Number of ants:%d\nSize:%d\n", t->n_ants, size);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_printf("%d ", t->ls[i][j]);
			++j;
		}
		ft_printf("\n");
		++i;
	}
}

void	lm_delete_node(void *mem, size_t size)
{
	size = 0;
	free(mem);
}

int		lm_list_to_array(t_table *t)
{
	t_node	**new;
	t_list	*tmp;
	t_node	*n;

	tmp = t->nl;
	if ((new = (t_node**)malloc(sizeof(t_node*) * t->size)) == NULL)
		return (-1);
	while (tmp)
	{
		n = (t_node*)tmp->content;
		if (!(new[n->id] = malloc(tmp->content_size)))
			return (-1);
		ft_memcpy(new[n->id], tmp->content, tmp->content_size);
		tmp = tmp->next;
	}
	ft_lstdel(&t->nl, lm_delete_node);
	t->ns = new;
	return (1);
}

void	print_node_arr(t_table *t)
{
	t_node	*n;
	int		i;

	i = 0;
	while (i < t->size)
	{
		n = t->ns[i];
		ft_printf("id:%d\nname:%s\nx:%d y:%d\nis_end_start:%d\n\n\n", n->id, n->name, n->x, n->y, n->is_end_start);
		i++;
	}
}

int		lm_init_table(t_table *t)
{
	char	**new;
	int		size;
	int		i;

	i = 0;
	size = ft_lstsize(t->nl);
	t->size = size;
	ft_lstiter(t->nl, print_node);
	lm_list_to_array(t);
	print_node_arr(t);
	if ((new = (char**)malloc(sizeof(char*) * size)) == NULL)
		return (-1);
	while (i < size)
	{
		if ((new[i] = (char*)malloc(sizeof(char) * size)) == NULL)
			return (-1);
		ft_bzero(new[i], size);
		++i;
	}
	t->ls = new;
	lm_print_table(t);
	return (1);
}

/*
void	lm_free(t_table *t)
{
	(void*)(t);
}
*/

void	split_free(char **split)
{
	int		i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int		lm_read_n_ants(t_table *t, char **split)
{
	t->n_ants = number_of_ants(split);
	if (t->n_ants == -1)
		return (-1);
	return (1);
}

int		lm_read_node(t_table *t, char **split, int end_start)
{
	static int	id = 0;

	if (is_valid_node(split) == 1)
	{
		fill_node(t, split, id, end_start);
		++id;
	}
	else
	{
		if (lm_read_link(t, split) == 1)
			return (2);
		else
			return (-1);
	}
	return (1);
}

int		lm_read_link(t_table *t, char **split)
{
	char	**l_split;

	l_split = is_valid_link(split);
	if (l_split == NULL)
		return (-1);
	fill_link(t, l_split[0], l_split[1]);
	split_free(l_split);
	return (1);
}

int		lm_read(t_table *t)
{
	char	*str;
	char	**split;
	int		comm;
	int		comm_tmp;
	char	flag;

	comm = 0;
	comm_tmp = 0;
	flag = 0;
	while (ft_gnl(0, &str, 0) > 0)
	{
		//add valid
		//add free split
		//detect comments
		ft_putstr(str);
		ft_putstr("\n");
		split = ft_strsplit(str, ' ');
		comm = is_comm(split, str);
		ft_printf("comm = %d\n", comm);
		if (comm == -1)
		{
			split_free(split);
			free(str);
			ft_error_msg();
		}
		if (comm == C_COMMENT)
		{
			split_free(split);
			free(str);
			continue ;
		}
		if (comm == C_END)
		{
			split_free(split);
			free(str);
			continue ;
		}
		if (comm == C_START)
		{
			split_free(split);
			free(str);
			continue ;
		}
		if (flag == 0)
		{
			ft_printf("read n_ants\n");
			if (lm_read_n_ants(t, split) == -1)
			{
				split_free(split);
				free(str);
				ft_error_msg();
			}
			else
				flag = 1;
		}
		else if (flag == 1)
		{
			ft_printf("read nodes\n");
			if ((flag = lm_read_node(t, split, comm_tmp)) == -1)
			{
				split_free(split);
				free(str);
				ft_error_msg();
			}
		}
		else if (flag == 2)
		{
			ft_printf("read links\n");
			if (lm_read_link(t, split) == -1)
			{
				split_free(split);
				free(str);
				ft_error_msg();
			}
		}
		split_free(split);
		free(str);
	}
	free(str);
	return (1);
}
