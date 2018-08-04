# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 12:48:33 by zbatik            #+#    #+#              #
#    Updated: 2018/08/04 15:45:41 by zbatik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS = push_swap
CHEKER = checker
LIB	= libft/libft.a
FLAGS	= -Wall -Werror -Wextra
FILES	= init.c display.c stack.c main.c ops.c read.c stack_check.c \
		   straight.c apply_op.c

all: $(LIB)
	gcc $(FLAGS) $(FILES) $(LIB) -o $(CHEKER)
$(LIB):
	make -s -C ./libft
$(PS) :
clean :
	rm -f $(PS) $(CHECKER)
fclean : clean
	rm -f $(LIB)
norm :
	norminette $(FILES)
re : fclean all
