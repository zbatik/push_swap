/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:01:19 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/15 14:01:15 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stackfind(t_stack *stack, char *opt)
{
	int		ret;

	if (!stack)
		return (0);
	ret = stack->n;
	while (stack)
	{
		if (ft_strequ(opt, "min"))
			ret = ft_min(ret, stack->n);
		else if (ft_strequ(opt, "max"))
			ret = ft_max(ret, stack->n);
		stack = stack->next;
	}
	return (ret);
}

int		ft_stackelmind(t_stack *stack, int n)
{
	int		ret;

	ret = 0;
	if (!stack)
		return (-1);
	while (stack)
	{
		if (stack->n == n)
			return (ret);
		ret++;
		stack = stack->next;
	}
	return (-1);
}

t_stack	*ft_stacknew(int n)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	new->n = n;
	new->a_rank = -1;
	new->b_rank = -1;
	new->a_dir = error;
	new->b_dir = error;
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
