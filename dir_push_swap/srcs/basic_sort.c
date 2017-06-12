/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 07:15:49 by elee              #+#    #+#             */
/*   Updated: 2016/11/18 14:07:00 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	rotate_check(int *a, int *b)
{
	int n;
	int	ret;

	ret = 0;
	n = 0;
	while (n++ < a[0])
	{
		if (check_sorted(a, b))
		{
			ret = 1;
			break ;
		}
		rotate(a);
	}
	ret = (ret == 1) ? n : 0;
	while (--n)
		reverse_rotate(a);
	return (ret);
}

void		basic_sort(int *a, int *b, char ***list)
{
	int	i;

	if (check_sorted(a, b))
		return ;
	while (!(i = rotate_check(a, b)))
	{
		if (a[a[0]] > a[a[0] - 1] && a[a[0]] > a[1] && swap(a))
			twod_realloc(list, "sa");
		if ((i = rotate_check(a, b)))
			break ;
		if (a[a[0]] < a[1] && reverse_rotate(a))
			twod_realloc(list, "rra");
		else if (a[a[0]] >= a[1] && rotate(a))
			twod_realloc(list, "ra");
	}
	if (i < a[0] / 2)
		while (--i && rotate(a))
			twod_realloc(list, "ra");
	else
		while (a[0] - i++ >= 0 && reverse_rotate(a))
			twod_realloc(list, "rra");
}
