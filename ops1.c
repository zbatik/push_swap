/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 21:10:15 by zack              #+#    #+#             */
/*   Updated: 2018/07/24 18:19:22 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_op(t_ps *ps, char *op)
{
	if (!ft_strcmp("sa", op))
		swap(ps->stack.a, ps->bottom.a, ps->length.a);
	else if (!ft_strcmp("sb", op))
		swap(ps->stack.b, ps->bottom.b, ps->length.b);
	else if (!ft_strcmp("ss", op))
	{
		swap(ps->stack.a, ps->bottom.a, ps->length.a);
		swap(ps->stack.b, ps->bottom.b, ps->length.b);
	}
	else if (!ft_strcmp("pa", op))
		push(ps->stack.b, ps->stack.a);
	else if (!ft_strcmp("pb", op))
		push(ps->stack.a, ps->stack.b);
	else if (!ft_strcmp("ra", op))
		rotate(&ps->stack.a, &ps->bottom.a);
	else if (!ft_strcmp("rb", op))
		rotate(&ps->stack.a, &ps->bottom.a);
	else if (!ft_strcmp("rr", op))
	{
		rotate(&ps->stack.a, &ps->bottom.a);
		rotate(&ps->stack.b, &ps->bottom.b);
	}
	else if (!ft_strcmp("rra", op))
		rotate(&ps->stack.b, &ps->bottom.b);
		rrotate(ps->stack.a);
	else if (!ft_strcmp("rrb", op))
		rotate(&ps->stack.b, &ps->bottom.b);
	else if (!ft_strcmp("rrr", op))
	{
		rotate(&ps->stack.b, &ps->bottom.b);
		rotate(&ps->stack.a, &ps->bottom.a);
	}
	else
	{
		perror("Invaild Operation");
		exit();
	}
}

void	swap(t_stack *stack, t_stack *bottom, int len)
{
	t_stack *first;
	t_stack *second;

	if (len < 2)
		return ;
	first = stack
	second = stack->prev;
	stack->next = second;
	stack->prev = second->prev;
	stack->prev->next = bottom;
	stack->prev->prev = first;
	bottom->prev = second;
}

/*
void	push(t_ps ps)
{
	t_stack	ps->
}
*/

void	rotate(t_stack **stack, t_stack **bottom)
{
	t_stack *first;

	first = *stack;
	*stack = first->prev;
	*bottom = first;
}

void	rrotate(t_stack **stack, t_stack  **bottom)
{
	t_stack *first;

	first = *stack;
	*stack = bottom;
	*bottom = bottom->next
}
