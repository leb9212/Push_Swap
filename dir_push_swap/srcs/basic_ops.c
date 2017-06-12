/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 22:51:33 by elee              #+#    #+#             */
/*   Updated: 2016/11/15 21:29:04 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int		swap(int *array)
{
	int		temp;
	int		index;

	if (array[0] < 2)
		return (1);
	index = array[0];
	temp = array[index];
	array[index] = array[index - 1];
	array[index - 1] = temp;
	return (1);
}

int		push(int *a, int *b)
{
	int		temp;

	if (b[0] == 0)
		return (1);
	temp = b[b[0]];
	b[b[0]] = 0;
	b[0]--;
	a[a[0] + 1] = temp;
	a[0]++;
	return (1);
}

int		rotate(int *array)
{
	int		*temp;
	int		index;

	if (array[0] < 2)
		return (1);
	temp = (int*)malloc(sizeof(int) * (array[0] + 1));
	temp[0] = array[0];
	index = 1;
	while (++index < array[0] + 1)
		temp[index] = array[index - 1];
	temp[1] = array[array[0]];
	index = 0;
	while (++index < array[0] + 1)
		array[index] = temp[index];
	free(temp);
	return (1);
}

int		reverse_rotate(int *array)
{
	int		*temp;
	int		index;

	if (array[0] < 2)
		return (1);
	temp = (int*)malloc(sizeof(int) * (array[0] + 1));
	temp[0] = array[0];
	index = 0;
	while (++index < array[0])
		temp[index] = array[index + 1];
	temp[array[0]] = array[1];
	index = 0;
	while (++index < array[0] + 1)
		array[index] = temp[index];
	free(temp);
	return (1);
}

int		apply_funcs(int *a, int *b, char *str)
{
	int		count;

	count = 0;
	(!ft_strcmp(str, "sa")) ? swap(a) : count++;
	(!ft_strcmp(str, "sb")) ? swap(b) : count++;
	(!ft_strcmp(str, "ss")) ? swap(a) : count++;
	(!ft_strcmp(str, "ss")) ? swap(b) : count++;
	(!ft_strcmp(str, "pa")) ? push(a, b) : count++;
	(!ft_strcmp(str, "pb")) ? push(b, a) : count++;
	(!ft_strcmp(str, "ra")) ? rotate(a) : count++;
	(!ft_strcmp(str, "rb")) ? rotate(b) : count++;
	(!ft_strcmp(str, "rr")) ? rotate(a) : count++;
	(!ft_strcmp(str, "rr")) ? rotate(b) : count++;
	(!ft_strcmp(str, "rra")) ? reverse_rotate(a) : count++;
	(!ft_strcmp(str, "rrb")) ? reverse_rotate(b) : count++;
	(!ft_strcmp(str, "rrr")) ? reverse_rotate(a) : count++;
	(!ft_strcmp(str, "rrr")) ? reverse_rotate(b) : count++;
	return ((count == 14) ? 0 : 1);
}
