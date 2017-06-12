/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 23:53:45 by elee              #+#    #+#             */
/*   Updated: 2016/11/15 21:29:09 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static long long	short_atoi(char *str)
{
	long long	n[2];

	n[0] = (*str == '-') ? -1 : 1;
	(n[1] = 0) == 0 && (*str == '+' || *str == '-') ? str++ : 0;
	while (*str >= '0' && *str <= '9')
		n[1] = n[1] * 10 + (*str++ - '0');
	return (*str ? 2147483648 : n[0] * n[1]);
}

int					check_input(int argc, char **argv, int *array)
{
	int			index;
	long long	temp;

	array[0] = argc - 1;
	index = argc;
	while (--index)
	{
		temp = short_atoi(argv[argc - index]);
		if (temp > 2147483647 || temp < -2147483648)
			return (0);
		array[index] = (int)temp;
	}
	return (1);
}

int					check_duplicate(int *array, int size)
{
	int		i;
	int		*tab;

	tab = (int*)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		tab[i] = array[i + 1];
	quick_sort(tab, 0, size - 1);
	i = -1;
	while (++i < size - 1)
	{
		if (tab[i] == tab[i + 1])
		{
			free(tab);
			return (0);
		}
	}
	free(tab);
	return (1);
}

int					check_sorted(int *a, int *b)
{
	int		i;

	if (b[0])
		return (0);
	i = 0;
	while (++i < a[0])
		if (a[i] <= a[i + 1])
			return (0);
	return (1);
}
