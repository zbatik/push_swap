/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:39:46 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/07 11:18:48 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_extremes(t_ps *ps)
{
	ps->min.a = ft_stackfind(ps->stack.a, "min");
	ps->min.b = ft_stackfind(ps->stack.b, "min");
	ps->max.a = ft_stackfind(ps->stack.a, "max");
	ps->max.b = ft_stackfind(ps->stack.b, "max");
}

t_op		convert_op(char *op)
{
	if (!ft_strcmp(op, "sa"))
		return (sa);
	else if (!ft_strcmp(op, "sb"))
		return (sb);
	else if (!ft_strcmp(op, "ss"))
		return (ss);
	else if (!ft_strcmp(op, "pa"))
		return (pa);
	else if (!ft_strcmp(op, "pb"))
		return (pb);
	else if (!ft_strcmp(op, "ra"))
		return (ra);
	else if (!ft_strcmp(op, "rb"))
		return (rb);
	else if (!ft_strcmp(op, "rr"))
		return (rr);
	else if (!ft_strcmp(op, "rra"))
		return (rra);
	else if (!ft_strcmp(op, "rrb"))
		return (rrb);
	else if (!ft_strcmp(op, "rrr"))
		return (rrr);
	return (error);
}

static void	apply_op1(t_ps *ps, t_op op)
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
	{
		push(&ps->stack.b, &ps->stack.a, &ps->length.b, &ps->length.a);
		set_extremes(ps);
	}
	else if (op == pb)
	{
		push(&ps->stack.a, &ps->stack.b, &ps->length.a, &ps->length.b);
		set_extremes(ps);
	}
	else if (op == ra)
		rotate(&ps->stack.a, ps->length.a);
	else if (op == rb)
		rotate(&ps->stack.b, ps->length.b);
}

static void	apply_op2(t_ps *ps, t_op op)
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

void		apply_op(t_ps *ps, t_op op)
{
	apply_op2(ps, op);
	apply_op1(ps, op);
}
