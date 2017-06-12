/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:26:02 by elee              #+#    #+#             */
/*   Updated: 2016/11/17 19:40:21 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	handle_error(int *a, int *b, int flag)
{
	(flag) ? write(2, "Error\n", 6) : 0;
	free(a);
	free(b);
	(flag) ? exit(0) : 0;
}

int			main(int argc, char **argv)
{
	int		*a;
	int		*b;
	char	**l1;

	l1 = ft_ptrnew(0);
	a = ft_intnew(argc);
	b = ft_intnew(argc);
	(!check_input(argc, argv, a)) ? handle_error(a, b, 1) : 0;
	(!check_duplicate(a, argc - 1)) ? handle_error(a, b, 1) : 0;
	(a[0] < 8) ? basic_sort(a, b, &l1) : advanced_sort(a, b, &l1);
	handle_error(a, b, 0);
	ft_putcarray(l1);
	ft_free_two(l1);
	return (1);
}
