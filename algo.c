/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 17:43:25 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/07 16:22:12 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_step(t_ps *ps, char *op)
{

	apply_op(ps, convert_op(op));
	ft_putendl(op);
	if (ps->debug)
		print_stacks(ps);
}

void		last_three(t_ps *ps, int min, int max)
{
	if (is_assending(ps->a.stack, ps->a.len))
		return ;
	if (ps->a.stack->n == min)
	{
		apply_step(ps, "rra");
		apply_step(ps, "sa");
	}
	else if (ps->a.stack->n == max)
	{
		apply_step(ps, "rr");
		last_three(ps, min, max);
	}
	else
	{
		apply_step(ps, "sa");
		last_three(ps, min, max);
	}
}

void		sort(t_ps *ps)
{
	int min;
	int len;

	if (is_assending(ps->a.stack, ps->a.len))
		return ;
	while (ps->a.len > 3)
	{
		min = ft_stackfind(ps->a.stack, "min");
		while (ps->a.stack->n != min)
		{
			len = ps->a.len / 2;
			if (ft_stackelmind(ps->a.stack, min) < len)
				apply_step(ps, "ra");
			else
				apply_step(ps, "rra");
		}
		apply_step(ps, "pb");
	}
	last_three(ps, ps->a.min, ps->a.max);
	while (ps->b.len != 0)
		apply_step(ps, "pa");
}
/*
void		split(t_ps *ps, t_stack *x, t_stack *y, int lenx, int leny)
{
	while (lenx > 3)
	{
		min = ft_stackfind(x, "min");
		while (x->n != min)
		{
			if (ft_stackelmind(x, min) < lenx / 2)
				apply_step(ps, "ra");
			else
				apply_step(ps, "rra");
		}
		apply_step(ps, "pb");
	}

}*/	
