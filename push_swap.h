/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:22:55 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/17 17:34:46 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/includes/libft.h"

typedef struct		s_stack
{
	int		n;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;

typedef struct		s_pair
{
	t_stack	*a;
	t_stack *b;
}			t_pair;

typedef struct		s_len
{
	int a;
	int b;
}			t_len;

typedef struct		s_ps
{
	t_pair	stack;
	t_pair	top;
	t_pair	bottom;
	t_len	length;
}			t_ps;

t_ps	*init_ps(int count, char **input);
void	post_error(void);
void	print_stack(t_stack *stack, int len);
void	ft_stpush(t_stack **stack, t_stack *in, t_stack *bottom);
t_stack	*ft_stnew(int n);

#endif
