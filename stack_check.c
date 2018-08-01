/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:57:42 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/01 11:29:17 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_assending(t_ps *ps)
{
	t_stack *aa;
	int		i;

	i = -1;
	aa = ps->stack.a;
	while (++i < ps->length.a - 1)
	{
		if (aa->n > aa->next->n)
			return (0);
		aa = aa->next;
	}
	return (1);
}
