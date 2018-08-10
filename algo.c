/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 17:43:25 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/10 14:10:40 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_step(t_ps *ps, t_op op)
{

	apply_op(ps, op);
	print_op(op);
	if (ps->debug)
		print_stacks(ps);
}

void		last_three(t_ps *ps, t_group *x, char ab)
{
	if (is_assending(x->stack, x->len))
		return ;
	if (x->stack->n == x->min)
	{
		apply_step(ps, ST_RROT(ab));
		apply_step(ps, ST_SWP(ab));
	}
	else if (x->stack->n == x->max)
	{
		apply_step(ps, ST_ROT(ab));
		last_three(ps, x, ab);
	}
	else
	{
		apply_step(ps, ST_SWP(ab));
		last_three(ps, x, ab);
	}
}

void		split(t_ps *ps, t_group *x, char ab)
{
	int min;
	

	while (x->len > 3)
	{
		min = ft_stackfind(x->stack, "min");
		while (x->stack->n != min)
		{
			if (ft_stackelmind(x->stack, min) < x->len / 2)
				apply_step(ps, ST_ROT(ab));
			else
				apply_step(ps, ST_RROT(ab));
		}
		apply_step(ps, ST_PUSH(ST_OPP(ab)));
	}
}

void		push_half(t_ps *ps, int len)
{
	int mid;
	int i;

	mid = ft_stackmed(ps->a.stack, len);
	i = -1;
	while (++i < len)
	{
		if (ps->a.stack->n >= mid)
			apply_step(ps, ST_PUSH('b'));
		else
			apply_step(ps, ST_ROT('a'));
	}
	print_stacks(ps);
}

void		sort(t_ps *ps)
{
	if (is_assending(ps->a.stack, ps->a.len))
		return ;
	push_half(ps, ps->a.len);
	//split(ps, &ps->a, 'a');
//	last_three(ps, &ps->a, 'a');
//	while (ps->b.len != 0)
//		apply_step(ps, ST_PUSH('a'));
}

