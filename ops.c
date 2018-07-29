/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 21:10:15 by zack              #+#    #+#             */
/*   Updated: 2018/07/29 13:57:33 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_op(t_ps *ps, t_op op)
{
	switch (op)
	{
		case sa :
			swap(&ps->stack.a, ps->length.a);
			break ;
		case sb :
			swap(&ps->stack.b, ps->length.b);
			break ;
		case ss :
			swap(&ps->stack.a, ps->length.a);
			swap(&ps->stack.b, ps->length.b);
			break ;
		case pa :
			push(&ps->stack.b, &ps->stack.a, &ps->length.b, &ps->length.a);
			break ;
		case pb :
			push(&ps->stack.a, &ps->stack.b, &ps->length.a, &ps->length.b);
			break ;
		case ra :
			rotate(&ps->stack.a, ps->length.a);
			break ;
		case rb :
			rotate(&ps->stack.b, ps->length.b);
			break ;
		case rr :
			rotate(&ps->stack.a, ps->length.a);
			rotate(&ps->stack.b, ps->length.b);
			break ;
		case rra :
			rrotate(&ps->stack.a, ps->length.a);
			break ;
		case rrb :
			rrotate(&ps->stack.b, ps->length.b);
			break ;
		case rrr :
			rrotate(&ps->stack.a, ps->length.a);
			rrotate(&ps->stack.b, ps->length.b);
			break ;
		case error :
			ft_puterror("Invaild Operation");
			exit(0);
	}
}

void	swap(t_stack **stack, int len)
{
	t_stack *first;
	t_stack *second;

	if (len < 2)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	push(t_stack **from, t_stack **to, int *len_from, int *len_to)
{
	t_stack *top;

	if (*from == NULL)
		return ;
	top = *from;
	*from = top->next;
	ft_stpush(to, top);
	*len_from -= 1;
	*len_to += 1;
}

void	rrotate(t_stack **stack, int len)
{
	int		i;
	t_stack	*bottom;

	if (len < 3)
	{
		swap(stack, len);
		return ;
	}
	i = -1;
	bottom = *stack;
	while (++i < len - 2)
		bottom = bottom->next;
	ft_stpush(stack, bottom->next);
	bottom->next = NULL;
}

void	rotate(t_stack **stack, int len)
{
	int i;
	t_stack *bottom;
	t_stack *top;

	if (len < 3)
	{
		swap(stack, len);
		return ;
	}
	top = (*stack)->next;
	bottom = *stack;
	i = -1;
	while (++i < len - 1)
		bottom = bottom->next;
	bottom->next = *stack;
	(*stack)->next = NULL;
	*stack = top;
}
