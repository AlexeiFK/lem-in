/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_print_final.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:21:03 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/12 23:53:43 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

/*
int		lm_get_next_id(int *path, int end)
{
	if (i != e)
		return (path[i]);
}
*/
/*
int		lm_path_size(int *path, int s, int e)
{
	int		i;
	int		c;

	c = 0;
	i = e;
	while (i != s)
	{
		i = path[i];
		++c;
	}
	return (c);
}
*/

char	*new_ant_path(int ant, const char *name)
{
	char	*itoa;
	char	*new;

	itoa = ft_itoa(ant);
	if (!(new = ft_strnew(3 + ft_strlen(itoa) + ft_strlen(name))))
		return (NULL);
	new[0] = 'L';
	ft_strcat(new, itoa);
	free(itoa);
	ft_strcat(new, "-");
	ft_strcat(new, name);
	ft_strcat(new, " ");
	return (new);
}

int		one_path_one_ant(t_table *t, int *path, int ant, int n)
{
	int		i;
	int		e;
	int		s;

	s = t->id_start;
	e = t->id_end;
	i = e;
//	t->result[n] = ft_free_strjoin(t->result[n], new_ant_path(ant, t->ns[i / 2]->name)); //malloc prot
//	ft_printf("L%d-%s n = %d", ant, t->ns[i / 2]->name, n);
//	i = path[i];
//	i = path[i];
	while (i != s)
	{
	//	t->result[n]
		if (i % 2 == 0)
		{
			t->result[n] = ft_free_strjoin(t->result[n], new_ant_path(ant, t->ns[i / 2]->name)); //malloc prot
//			else
//			{
//				t->result[n] = ft_free_strjoin();
//			}
			--n;
		//	ft_printf("%s", new_ant_path(ant, t->ns[i / 2]->name));
		}
		i = path[i];
	}
	return (1);
}

char	**lm_create_res(t_table *t, int *split, int **paths, int flow)
{
	int		i;
	int		j;
	int		size;
	int		ant;
	char	**result;

	i = 0;
	size = (lm_path_size(paths[0], t->id_start, t->id_end) - 1) / 2 + split[0];
	if (!(result = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	while (i < size)
	{
		result[i] = ft_strnew(1);
		++i;
	}
	i = 0;
	t->result = result;
	ant = 1;
	while (i < flow)
	{
		j = 0;
		while (j < split[i])
		{
	//		ft_printf("\n", ant);
			one_path_one_ant(t, paths[i], ant, (lm_path_size(paths[i], t->id_start, t->id_end) - 1) / 2  + j);
			++j;
			++ant;
		}
		++i;
	}
	return (result);
}

int		lm_print_final(t_table *t, int *split, int **paths, int flow)
{
	char	**result;
	int		i;
	int		size;

	result = lm_create_res(t, split, paths, flow); //malloc 
	i = 0;
	size = (lm_path_size(paths[0], t->id_start, t->id_end) - 1) / 2 + split[0];
	while (i < size)
	{
		ft_putstr(result[i]);
		ft_putstr("\n");
		free(result[i]);
		i++;
	}
	free(result);
	ft_printf("final_res:%d\n", size - 1);
	return (1);
}
