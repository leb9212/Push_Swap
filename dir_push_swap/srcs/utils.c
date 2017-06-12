/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:08:58 by elee              #+#    #+#             */
/*   Updated: 2016/11/17 20:42:32 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int			get_min(int *a)
{
	int		min;
	int		i;

	i = 1;
	min = a[1];
	while (++i <= a[0])
		min = (min < a[i]) ? min : a[i];
	return (min);
}

int			get_max(int *a)
{
	int		max;
	int		i;

	i = 1;
	max = a[1];
	while (++i <= a[0])
		max = (max > a[i]) ? max : a[i];
	return (max);
}

int			twod_realloc(char ***list, char *ins)
{
	int		len;
	char	**new;
	int		index;

	len = ft_ptrlen(*list);
	new = ft_ptrnew(len);
	index = -1;
	while (++index < len)
		new[index] = ft_strdup((*list)[index]);
	ft_free_two(*list);
	*list = ft_ptrnew(len + 1);
	index = -1;
	while (++index < len)
		(*list)[index] = ft_strdup(new[index]);
	(*list)[index] = ft_strdup(ins);
	ft_free_two(new);
	return (1);
}

int			ft_putcarray(char **list)
{
	int		index;

	index = -1;
	while (list[++index])
		ft_putendl(list[index]);
	return (1);
}
