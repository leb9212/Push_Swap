/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 20:53:34 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:51:28 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	handle_error(int *a, int *b, int *options)
{
	if (options[1])
		write(2, "\e[31mError\n", 11);
	else
		write(2, "Error\n", 6);
	free(a);
	free(b);
	exit(0);
}

static int	set_options(int *argc, char **argv, int *options)
{
	int		i;
	int		copy;
	int		ret;

	ret = 0;
	i = 1;
	copy = *argc;
	while (i < copy && (!ft_strcmp(argv[i], "-c") || !ft_strcmp(argv[i], "-v")
				|| !ft_strcmp(argv[i], "-cv") || !ft_strcmp(argv[i], "-vc")))
	{
		if ((!ft_strcmp(argv[i], "-vc") || !ft_strcmp(argv[i], "-cv"))
				&& (*argc -= 1) && ++ret)
		{
			options[0] = 1;
			options[1] = 1;
		}
		if (!ft_strcmp(argv[i], "-v") && (*argc -= 1) && ++ret)
			options[0] = 1;
		if (!ft_strcmp(argv[i], "-c") && (*argc -= 1) && ++ret)
			options[1] = 1;
		i++;
	}
	return (ret);
}

static int	color_option(char *ins)
{
	int		color;

	if (!ft_strcmp(ins, "sa") || !ft_strcmp(ins, "sb") || !ft_strcmp(ins, "ss"))
		color = 31;
	if (!ft_strcmp(ins, "ra") || !ft_strcmp(ins, "rb") || !ft_strcmp(ins, "rr"))
		color = 32;
	if (!ft_strcmp(ins, "rra") || !ft_strcmp(ins, "rrb")
			|| !ft_strcmp(ins, "rrr"))
		color = 33;
	if (!ft_strcmp(ins, "pa") || !ft_strcmp(ins, "pb"))
		color = 34;
	return (color);
}

static void	print_status(int *a, int *b, char *status, int *options)
{
	int		height;
	int		index;
	int		color;

	height = MAX(a[0], b[0]);
	index = -1;
	color = (options[1]) ? color_option(status) : 39;
	ft_printf("\e[39mInstruction: %s\n", status);
	ft_printf("\e[%dm||  Stack A  ||  Stack B  ||\n", color);
	while (++index < height)
	{
		if (height - index <= a[0])
			ft_printf("\e[%dm||%-11d||", color, a[height - index]);
		else
			ft_printf("\e[%dm||           ||", color);
		if (height - index <= b[0])
			ft_printf("\e[%dm%-11d||\n", color, b[height - index]);
		else
			ft_printf("\e[%dm           ||\n", color);
	}
}

int			main(int argc, char **argv)
{
	char	*line;
	int		*a;
	int		*b;
	int		*options;

	options = ft_intnew(2);
	argv += set_options(&argc, argv, options);
	a = ft_intnew(argc);
	b = ft_intnew(argc);
	(!check_input(argc, argv, a)) ? handle_error(a, b, options) : 0;
	(!check_duplicate(a, argc - 1)) ? handle_error(a, b, options) : 0;
	(options[0] == 1) ? print_status(a, b, "Beginning", options) : 0;
	while (get_next_line(0, &line) > 0)
	{
		(!apply_funcs(a, b, line)) ? handle_error(a, b, options) : 0;
		(options[0] == 1) ? print_status(a, b, line, options) : 0;
		free(line);
	}
	(options[1] && !check_sorted(a, b)) ? ft_printf("\e[31mKO\n") : 0;
	(options[1] && check_sorted(a, b)) ? ft_printf("\e[32mOK\n") : 0;
	(!options[1] && !check_sorted(a, b)) ? ft_printf("KO\n") : 0;
	(!options[1] && check_sorted(a, b)) ? ft_printf("OK\n") : 0;
	free(a);
	free(b);
	return (1);
}
