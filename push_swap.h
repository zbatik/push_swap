/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:22:55 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/04 15:38:36 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

#define CL(x) (ps->colour ? x : na)

typedef enum
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	error,
}	t_op;

typedef struct	s_stack
{
	int				n;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_pair
{
	t_stack	*a;
	t_stack *b;
}				t_pair;

typedef struct	s_len
{
	int a;
	int b;
}				t_len;

typedef struct	s_ps
{
	int		max;
	int		min;
	t_bool	debug;
	t_bool	colour;
	t_bool	file;
	t_pair	stack;
	t_len	length;
}				t_ps;

t_ps			*init_ps(int count, char **input);

void			print_stack(t_stack *stack);
void			print_stacks(t_ps *ps);
void			print_result(t_ps *ps);

void			debug(t_ps *ps);
void			straight(t_ps *ps);

void			ft_stpush(t_stack **stack, t_stack *item);

void			apply_op(t_ps *ps, t_op op);
void			swap(t_stack **stack, int len);
void			push(t_stack **from, t_stack **to, int *len_from, int *len_to);

t_dblist		*store_op(char *op_str, t_op op);
void			rotate(t_stack **stack, int len);
void			rrotate(t_stack **stack, int len);
t_op			convert_op(char *op);
int				is_assending(t_ps *ps);
t_stack			*ft_stnew(int n);

#endif
