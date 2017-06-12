/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 21:45:00 by elee              #+#    #+#             */
/*   Updated: 2016/11/17 21:45:03 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	rotate_count(int *a, int n)
{
	int		i;
	int		index;

	i = 0;
	index = a[0];
	while (index > 0)
	{
		if (a[index] == n)
			return (i);
		index--;
		i++;
	}
	return (0);
}

static int	reverse_rotate_count(int *a, int n)
{
	int		i;
	int		index;

	i = 1;
	index = 1;
	while (index <= a[0])
	{
		if (a[index] == n)
			return (-i);
		index++;
		i++;
	}
	return (0);
}

int			count_to_top(int *a, int n)
{
	int		pos;
	int		i;
	int		index;

	pos = 1;
	i = 1;
	index = a[0];
	while (index > 0)
	{
		if (a[index] == n)
			pos = i;
		index--;
		i++;
	}
	if (pos <= ((a[0] + 1) / 2))
		return (rotate_count(a, n));
	else
		return (reverse_rotate_count(a, n));
	return (0);
}

int			count_to_pos(int *a, int n)
{
	int		max;
	int		min;
	int		nextval;
	int		index;

	nextval = -1;
	max = get_max(a);
	min = get_min(a);
	if (n > max || n < min)
		return (count_to_top(a, max));
	else
	{
		nextval = min;
		index = a[0];
		while (index > 0)
		{
			if (a[index] < n && a[index] > nextval)
				nextval = a[index];
			index--;
		}
		return (count_to_top(a, nextval));
	}
}
