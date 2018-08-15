/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 17:43:25 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/15 14:04:52 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		last_three(t_ps *ps, t_group *a)
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

/*
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
*/
