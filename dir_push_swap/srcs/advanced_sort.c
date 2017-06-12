/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 22:30:31 by elee              #+#    #+#             */
/*   Updated: 2016/11/17 22:22:20 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	rotate_separately(int *a, int *b, char ***list, t_rotate *m)
{
	if (m->count_a > 0)
	{
		(rotate(a)) ? twod_realloc(list, "ra") : 0;
		(m->count_a)--;
	}
	else if (m->count_a < 0)
	{
		(reverse_rotate(a)) ? twod_realloc(list, "rra") : 0;
		(m->count_a)++;
	}
	if (m->count_b > 0)
	{
		(rotate(b)) ? twod_realloc(list, "rb") : 0;
		(m->count_b)--;
	}
	else if (m->count_b < 0)
	{
		(reverse_rotate(b)) ? twod_realloc(list, "rrb") : 0;
		(m->count_b)++;
	}
}

static void	rotate_together(int *a, int *b, char ***list, t_rotate *m)
{
	while (m->count_a > 0 && m->count_b > 0)
	{
		rotate(a);
		rotate(b);
		twod_realloc(list, "rr");
		(m->count_a)--;
		(m->count_b)--;
	}
	while (m->count_a < 0 && m->count_b < 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		twod_realloc(list, "rrr");
		(m->count_a)++;
		(m->count_b)++;
	}
	rotate_separately(a, b, list, m);
}

static void	find_best_pb(int *a, int *b, char ***list)
{
	int			i;
	t_rotate	*m;

	i = a[0];
	m = rotate_init();
	while (i)
	{
		m->temp_a = count_to_top(a, a[i]);
		m->temp_b = count_to_pos(b, a[i]);
		if (m->temp_a * m->temp_b < 0)
			m->temp_total = 1 + ABS(m->temp_a) + ABS(m->temp_b);
		else
			m->temp_total = 1 + MAX(ABS(m->temp_a), ABS(m->temp_b));
		if (m->init == 0 || m->temp_total < m->count_total)
			copy_temp(m);
		i--;
	}
	while (m->count_a || m->count_b)
		rotate_together(a, b, list, m);
	free(m);
	(push(b, a)) ? twod_realloc(list, "pb") : 0;
}

void		advanced_sort(int *a, int *b, char ***list)
{
	int		mb;

	if (!check_sorted(a, b))
	{
		(push(b, a)) ? twod_realloc(list, "pb") : 0;
		while (a[0])
			find_best_pb(a, b, list);
		mb = count_to_top(b, get_max(b));
		while (mb)
		{
			if (mb > 0 && mb--)
				(rotate(b)) ? twod_realloc(list, "rb") : 0;
			else if (mb < 0 && mb++)
				(reverse_rotate(b)) ? twod_realloc(list, "rrb") : 0;
		}
		while (b[0])
			(push(a, b)) ? twod_realloc(list, "pa") : 0;
	}
}
