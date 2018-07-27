# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 12:48:33 by zbatik            #+#    #+#              #
#    Updated: 2018/07/27 17:07:41 by zbatik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS = push_swap
CHEKER = checker
LIB	= libft/libft.a
FLAGS	= -Wall -Werror -Wextra
FILES	= init.c display.c stack.c main.c ops.c

all: $(LIB) $(PS) $(CHECKER) 
$(LIB):
	make -s -C ./libft
$(PS) :
	gcc $(FLAGS) $(FILES) $(LIB) -o $(PS)
$(CHECKER) :
clean :
	rm -f $(PS) $(CHECKER)
fclean : clean
	rm -f $(LIB)
re : fclean all
