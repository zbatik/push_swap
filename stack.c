/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:01:19 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/06 17:43:11 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stackmin(t_stack *stack)
{
	t_stack	*aa;
	int		min;

	
	aa = stack;
	min = aa->n;
	while (aa)
	{
		min = ft_min(min, aa->n);
		aa = aa->next;
	}
	return (min);
}

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

t_stack	*ft_stacknew(int n)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	new->n = n;
	new->next = NULL;
	return (new);
}

void	ft_stackpush(t_stack **stack, t_stack *item)
{
	item->next = *stack;
	*stack = item;
}

void	ft_stackdel(t_stack **stack)
{
	t_stack	*next;

	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = NULL;
		*stack = next;
	}
}
