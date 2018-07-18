/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 21:10:15 by zack              #+#    #+#             */
/*   Updated: 2018/07/18 21:33:09 by zack             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_op(t_ps *ps, char *op)
{
	if (!ft_strcmp("sa", op))
		swap(ps->stack.a);
	else if (!ft_strcmp("sb", op))
		swap(ps->stack.b);
	else if (!ft_strcmp("ss", op))
	{
		swap(ps->stack.a);
		swap(ps->stack.b);
	}
	else if (!ft_strcmp("pa", op))
		push(ps->stack.b, ps->stack.a);
	else if (!ft_strcmp("pb", op))
		push(ps->stack.a, ps->stack.b);
	else if (!ft_strcmp("ra", op))
		rotate(ps->stack.a);
	else if (!ft_strcmp("rb", op))
		rotate(ps->stack.b);
	else if (!ft_strcmp("rr", op))
	{
		rotate(ps->stack.a);
		rotate(ps->stack.b);
	}
	else if (!ft_strcmp("rra", op))
		rrotate(ps->stack.a);
	else if (!ft_strcmp("rrb", op))
		rrotate(ps->stack.b);
	else if (!ft_strcmp("rrr", op))
	{
		rrotate(ps->stack.a);
		rrotate(ps->stack.b);
	}
	else
	{
		perror("Invaild Operation");
		exit();
	}
}

void	swap(t_stack *stack)
{
}

void	push(t_stack *from, t_stack *to)
{
}

void	rotate(t_stack *stack)
{
}

void	rrotate(t_stack *stack)
{
}
