/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_edm_karp2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 23:10:46 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/17 15:01:57 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"
#include "libft.h"

void		print_ints(int *res, int size)
{
	int		k;

	k = 0;
	while (k < size)
	{
		ft_printf("res[%d]=%d\n", k, res[k]);
		++k;
	}
}

int			is_es(int s, int e, int n1, int n2)
{
	if (n1 == s && n2 == (s + 1))
		return (1);
	if (n2 == s && n1 == (s + 1))
		return (1);
	if (n1 == e && n2 == (e - 1))
		return (1);
	if (n2 == e && n1 == (s - 1))
		return (1);
	return (0);
}

void		arrintset(int *res, int size, int set)
{
	int	i;

	i = 0;
	while (i < size)
	{
		res[i] = set;
		++i;
	}
}

int			*arrintcpy(int *arr, int size)
{
	int		*new;
	int		i;

	if (!(new = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = arr[i];
		++i;
	}
	return (new);
}

int			**fls_copy(int **src, int size)
{
	int		**tmpfls;
	int		i;

	i = 0;
	tmpfls = (int**)malloc(sizeof(int*) * size);
	if (!tmpfls)
		return (NULL);
	while (i < size)
	{
		tmpfls[i] = (int*)malloc(sizeof(int) * size);
		ft_memcpy(tmpfls[i], src[i], sizeof(int) * size);
		++i;
	}
	return (tmpfls);
}
