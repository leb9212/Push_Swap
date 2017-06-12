# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 14:34:35 by elee              #+#    #+#              #
#    Updated: 2017/06/11 17:28:44 by elee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker
NAME_PUSHSWAP = push_swap

PATH_LIBFT = ./libft
PATH_CHECKER = ./dir_checker
PATH_PUSHSWAP = ./dir_push_swap

all:
	make -C $(PATH_LIBFT)
	make -C $(PATH_CHECKER)
	make -C $(PATH_PUSHSWAP)
	cp $(PATH_CHECKER)/$(NAME_CHECKER) .
	cp $(PATH_PUSHSWAP)/$(NAME_PUSHSWAP) .

clean:
	make -C $(PATH_LIBFT) clean
	make -C $(PATH_CHECKER) clean
	make -C $(PATH_PUSHSWAP) clean

fclean:
	make -C $(PATH_LIBFT) fclean
	make -C $(PATH_CHECKER) fclean
	make -C $(PATH_PUSHSWAP) fclean
	/bin/rm -f $(NAME_CHECKER) $(NAME_PUSHSWAP)

re: fclean all

.PHONY: all clean fclean re
