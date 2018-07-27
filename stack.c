/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:01:19 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/27 15:26:15 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stnew(int n)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	new->n = n;
	new->next = NULL;
	return (new);
}

void	ft_stpush(t_stack **stack, t_stack *item)
{
	item->next = *stack;
	*stack = item;
}
