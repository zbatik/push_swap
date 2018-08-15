/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:13:27 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/15 14:17:49 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		apply_step(t_ps *ps, t_op op)
{
	apply_op(ps, op);
	print_op(ps, op);
	if (ps->debug)
		print_stacks(ps);
}

static void	last_three(t_ps *ps, t_group *a)
{
	if (is_assending(a->stack, a->len))
		return ;
	if (a->stack->n == a->min)
	{
		apply_step(ps, rra);
		apply_step(ps, sa);
	}
	else if (a->stack->n == a->max)
	{
		apply_step(ps, ra);
		last_three(ps, a);
	}
	else
	{
		apply_step(ps, sa);
		last_three(ps, a);
	}
}

static void	reset(t_ps *ps)
{
	int		ind;
	t_op	op;

	ind = ft_stackelmind(ps->b.stack, ft_stackfind(ps->b.stack, "max"));
	if (ind > ps->b.len / 2)
	{
		op = rrb;
		ind = ps->b.len - ind;
	}
	else
		op = rb;
	while (ind-- != 0)
		apply_step(ps, op);
}

void		sort(t_ps *ps)
{
	if (is_assending(ps->a.stack, ps->a.len))
		return ;
	if (ps->a.len == 3)
	{
		last_three(ps, &ps->a);
		return ;
	}
	apply_step(ps, pb);
	apply_step(ps, pb);
	while (ps->a.len != 0)
	{
		rank(ps);
		best(ps);
	}
	reset(ps);
	while (ps->b.len != 0)
		apply_step(ps, pa);
}
