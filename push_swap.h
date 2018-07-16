/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:22:55 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/16 19:47:41 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct		s_stack
{
	int	n;
	t_stack	*next;
	t_stack	*prev;
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
}			t_len

typedef struct		s_ps
{
	t_stack		a;
	t_stack		b;
	t_placeholder	top;
	t_placeholder	bottom;
	t_len		length;
}

void	post_error(void);
#endif
