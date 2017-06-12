# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/27 21:33:26 by elee              #+#    #+#              #
#    Updated: 2016/11/18 14:08:38 by elee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = basic_ops.c helper.c checker.c

OBJS = $(SRCS:.c=.o)

INCS = includes/

all: $(NAME)

$(NAME):
	mkdir -p objs/
	$(CC) $(CFLAGS) -c $(addprefix srcs/, $(SRCS)) -I$(INCS)
	mv $(OBJS) objs/
	gcc $(addprefix objs/, $(OBJS)) ../../libft/libft.a -o $(NAME)

clean:
	/bin/rm -rf $(addprefix objs/, $(OBJS))

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
