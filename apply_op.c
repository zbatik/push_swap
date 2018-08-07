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
	ps->a.min = ft_stackfind(ps->a.stack, "min");
	ps->b.min = ft_stackfind(ps->b.stack, "min");
	ps->a.max = ft_stackfind(ps->a.stack, "max");
	ps->b.max = ft_stackfind(ps->b.stack, "max");
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
		swap(&ps->a.stack, ps->a.len);
	else if (op == sb)
		swap(&ps->b.stack, ps->b.len);
	else if (op == ss)
	{
		swap(&ps->a.stack, ps->a.len);
		swap(&ps->b.stack, ps->b.len);
	}
	else if (op == pa)
	{
		push(&ps->b.stack, &ps->a.stack, &ps->b.len, &ps->a.len);
		set_extremes(ps);
	}
	else if (op == pb)
	{
		push(&ps->a.stack, &ps->b.stack, &ps->a.len, &ps->b.len);
		set_extremes(ps);
	}
	else if (op == ra)
		rotate(&ps->a.stack, ps->a.len);
	else if (op == rb)
		rotate(&ps->b.stack, ps->b.len);
}

static void	apply_op2(t_ps *ps, t_op op)
{
	if (op == rr)
	{
		rotate(&ps->a.stack, ps->a.len);
		rotate(&ps->b.stack, ps->b.len);
	}
	else if (op == rra)
		rrotate(&ps->a.stack, ps->a.len);
	else if (op == rrb)
		rrotate(&ps->b.stack, ps->b.len);
	else if (op == rrr)
	{
		rrotate(&ps->a.stack, ps->a.len);
		rrotate(&ps->b.stack, ps->b.len);
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
