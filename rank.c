/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 18:46:46 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/13 18:49:36 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_rank(t_stack *a, int len)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (a)
	{
		if (count++ <= len / 2)
		{
			a->a_rank = i++;
			a->a_dir = ra;
		}
		else
		{
			a->a_rank = len - i++;
			a->a_dir = rra;
		}
		a = a->next;
	}
}

static int	b_rank_elm(t_stack *a, t_group *b)
{
	int		count;
	t_stack	*stack;

	stack = b->stack;
	count = 0;
	if (a->n > ft_stackfind(stack, "max"))
	{
		a->b_dir = rb;
		return (ft_stackelmind(stack, ft_stackfind(stack, "max")));
	}
	if (a->n < ft_stackfind(stack, "min"))
	{
		a->b_dir = rb;
		return (ft_stackelmind(stack, ft_stackfind(stack, "max")));
	}
	while (stack->next)
	{
		count++;
		if (a->n < stack->n && a->n > stack->next->n)
		{
			if (count > b->len / 2)
			{
				a->b_dir = rrb;
				return (b->len - count);
			}
			else
			{
				a->b_dir = rb;
				return (count);
			}
		}
		stack = stack->next;
	}
	a->b_dir = rb;
	return (0);
}

static void	b_rank(t_stack *a, t_group *b)
{
	while (a)
	{
		a->b_rank = b_rank_elm(a, b);
		a = a->next;
	}
}

void		rank(t_ps *ps)
{
	a_rank(ps->a.stack, ps->a.len);
	b_rank(ps->a.stack, &ps->b);
}
