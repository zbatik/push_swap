/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:39:46 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/04 16:55:19 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_op1(t_ps *ps, t_op op)
{
	if (op == sa)
		swap(&ps->stack.a, ps->length.a);
	else if (op == sb)
		swap(&ps->stack.b, ps->length.b);
	else if (op == ss)
	{
		swap(&ps->stack.a, ps->length.a);
		swap(&ps->stack.b, ps->length.b);
	}
	else if (op == pa)
		push(&ps->stack.b, &ps->stack.a, &ps->length.b, &ps->length.a);
	else if (op == pb)
		push(&ps->stack.a, &ps->stack.b, &ps->length.a, &ps->length.b);
	else if (op == ra)
		rotate(&ps->stack.a, ps->length.a);
	else if (op == rb)
		rotate(&ps->stack.b, ps->length.b);
}

void	apply_op2(t_ps *ps, t_op op)
{
	if (op == rr)
	{
		rotate(&ps->stack.a, ps->length.a);
		rotate(&ps->stack.b, ps->length.b);
	}
	else if (op == rra)
		rrotate(&ps->stack.a, ps->length.a);
	else if (op == rrb)
		rrotate(&ps->stack.b, ps->length.b);
	else if (op == rrr)
	{
		rrotate(&ps->stack.a, ps->length.a);
		rrotate(&ps->stack.b, ps->length.b);
	}
	else if (op == error)
	{
		ft_puterror("Invaild Operation");
		exit(-1);
	}
}

void	apply_op(t_ps *ps, t_op op)
{
	apply_op2(ps, op);
	apply_op1(ps, op);
}
