/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:22:55 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/17 12:47:00 by zbatik           ###   ########.fr       */
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

typedef struct		s_placeholder
{
	t_stack	a;
	t_stack b;
}			t_placeholder;

typedef struct		s_len
{
	int a;
	int b;
}			t_len;

typedef struct		s_ps
{
	t_stack		a;
	t_stack		b;
	t_placeholder	top;
	t_placeholder	bottom;
	t_len		length;
}			t_ps;

void	post_error(void);
void	print_stack(t_stack *stack, int len);
void	ft_stpush(t_stack **stack, t_stack *in, t_stack *bottom);
t_stack	*ft_stnew(int n);

#endif
