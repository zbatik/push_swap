/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 17:43:25 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/06 18:08:22 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_step(t_ps *ps, char *op)
{

	apply_op(ps, convert_op(op));
	ft_putendl(op);
//	print_stacks(ps);
}

void		sort(t_ps *ps)
{
	int min;

	while (ps->stack.a != 0)
	{
		min = ft_stackmin(ps->stack.a);
		while (ps->stack.a->n != min)
		{
			apply_step(ps, "ra");
		}
		apply_step(ps, "pb");
	}
	while (ps->length.b != 0)
		apply_step(ps, "pa");
}
