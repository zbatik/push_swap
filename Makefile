# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 12:48:33 by zbatik            #+#    #+#              #
#    Updated: 2018/07/17 17:21:50 by zbatik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN	= push_swap
LIB	= libft/libft.a
FLAGS	= -Wall -Werror -Wextra
FILES	= init.c display.c stack.c main.c

all: $(LIB)
	gcc $(FLAGS) $(FILES) $(LIB) -o $(BIN)
$(LIB):
	make -s -C ./libft
