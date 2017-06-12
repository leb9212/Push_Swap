/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 21:44:49 by elee              #+#    #+#             */
/*   Updated: 2016/11/17 22:21:36 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_rotate	*rotate_init(void)
{
	t_rotate	*rotate;

	rotate = (t_rotate*)malloc(sizeof(t_rotate));
	rotate->init = 0;
	rotate->count_a = 0;
	rotate->count_b = 0;
	rotate->count_total = 0;
	rotate->temp_a = 0;
	rotate->temp_b = 0;
	rotate->temp_total = 0;
	return (rotate);
}

void		copy_temp(t_rotate *m)
{
	m->init = 1;
	m->count_a = m->temp_a;
	m->count_b = m->temp_b;
	m->count_total = m->temp_total;
}
