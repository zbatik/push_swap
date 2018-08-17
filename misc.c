/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:36:22 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/17 17:47:09 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean(t_ps **ps)
{
	ft_stackdel(&(*ps)->a.stack);
	(*ps)->a.stack = NULL;
	ft_stackdel(&(*ps)->b.stack);
	(*ps)->b.stack = NULL;
	free(*ps);
	*ps = NULL;
}

void	apply_step(t_ps *ps, t_op op)
{
	apply_op(ps, op);
	print_op(ps, op);
	if (ps->debug)
		print_stacks(ps);
}
