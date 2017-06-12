/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 21:45:26 by elee              #+#    #+#             */
/*   Updated: 2016/11/17 22:22:37 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_rotate
{
	int		init;
	int		count_a;
	int		count_b;
	int		count_total;
	int		temp_a;
	int		temp_b;
	int		temp_total;
}				t_rotate;

t_rotate		*rotate_init(void);
void			copy_temp(t_rotate *m);
int				count_to_top(int *a, int n);
int				count_to_pos(int *a, int n);

int				get_min(int *a);
int				get_max(int *a);
int				twod_realloc(char ***list, char *ins);
int				ft_putcarray(char **list);

int				check_input(int argc, char **argv, int *array);
int				check_duplicate(int *array, int size);
int				check_sorted(int *a, int *b);
int				apply_funcs(int *a, int *b, char *str);

void			basic_sort(int *a, int *b, char ***list);
void			advanced_sort(int *a, int *b, char ***list);

int				swap(int *array);
int				push(int *a, int *b);
int				rotate(int *array);
int				reverse_rotate(int *array);

#endif
