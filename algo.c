/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 17:43:25 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/07 14:21:39 by zbatik           ###   ########.fr       */
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

void		last_three(t_ps *ps, int len, int min, int max)
{
	len = 0;
	if (is_assending(ps->stack.a, ps->length.a))
		return ;
	if (ps->stack.a->n == min)
	{
		apply_step(ps, "rra");
		apply_step(ps, "sa");
	}
	else if (ps->stack.a->n == max)
	{
		apply_step(ps, "rr");
		last_three(ps, len, min, max);
	}
	else
	{
		apply_step(ps, "sa");
		last_three(ps, len, min, max);
	}
}

void		sort(t_ps *ps)
{
	int min;
	int len;

	if (is_assending(ps->stack.a, ps->length.a))
		return ;
	while (ps->length.a > 3)
	{
		min = ft_stackfind(ps->stack.a, "min");
		while (ps->stack.a->n != min)
		{
			len = ps->length.a / 2;
			if (ft_stackelmind(ps->stack.a, min) < len)
				apply_step(ps, "ra");
			else
				apply_step(ps, "rra");
		}
		apply_step(ps, "pb");
	}
	last_three(ps, ps->length.a,  ps->min.a, ps->max.a);
	while (ps->length.b != 0)
		apply_step(ps, "pa");
}
