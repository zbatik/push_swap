# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 12:48:33 by zbatik            #+#    #+#              #
#    Updated: 2018/08/19 12:49:25 by event            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS				= push_swap
CHECKER			= checker
LIB				= libft/libft.a
FLAGS			=  -Wall -Werror -Wextra
SHARED_FILES	= init.c display.c stack.c check_input.c apply_op.c ops.c misc.c
CHECK_FILES		= main_checker.c mode.c
PS_FILES		= main_pushswap.c algo.c rank.c best.c

all: clean $(LIB) $(CHECKER) $(PS)
$(LIB):
	make -s -C ./libft
$(CHECKER) : $(LIB)
	gcc $(FLAGS) $(SHARED_FILES) $(CHECK_FILES) $(LIB) -o $(CHECKER)
$(PS) : $(LIB)
	gcc $(FLAGS) $(SHARED_FILES) $(PS_FILES) $(LIB) -o $(PS)
clean :
	rm -f $(PS) $(CHECKER)
fclean : clean
	rm -f $(LIB)
norm :
	norminette $(SHARED_FILES) $(CHECK_FILES) $(PS_FILES) *.h
re : fclean all
