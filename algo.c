/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:13:27 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/13 15:46:32 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_step(t_ps *ps, t_op op)
{

	apply_op(ps, op);
	print_op(ps, op);
	if (ps->debug)
		print_stacks(ps);
}

void	a_rank(t_stack *a, int len)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (a)
	{
		if (count++ <=	len / 2)
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

int		b_rank_elm(t_stack *a, t_group *b)
{
	int count;
	t_stack *stack;

	stack = b->stack;
	count = 0;
	if (a->n > ft_stackfind(b->stack, "max"))
	{
		a->b_dir = rb;
		return (ft_stackelmind(b->stack, ft_stackfind(b->stack, "max")));
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
	a->b_dir = rrb;
	return (0);
}

void	b_rank(t_stack *a, t_group *b)
{
	while (a)
	{
		a->b_rank = b_rank_elm(a, b);
		a = a->next;
	}
}

void	rank(t_ps *ps)
{
	a_rank(ps->a.stack, ps->a.len);
	b_rank(ps->a.stack, &ps->b);
}

t_stack	*best_ind(t_stack *a)
{
	int score;
	t_stack *top;

	top = a;
	score = 2147483647;
	while (a)
	{
		if (score > a->a_rank + a->b_rank)
			score = a->a_rank + a->b_rank;
		a = a->next;
	}
	a = top;
	while (a)
	{
		if (a->a_rank + a->b_rank == score)
			return (a);
		a = a->next;
	}
	return (a);
}

void	best(t_ps *ps)
{
	t_stack	*node;

	node = best_ind(ps->a.stack);
	while (node->a_rank != 0)
	{
		apply_step(ps, node->a_dir);
		node->a_rank -= 1;
	}
	while(node->b_rank != 0)
	{
		apply_step(ps, node->b_dir);
		node->b_rank -= 1;
	}
	apply_step(ps, pb);
}

void	reset(t_ps *ps)
{
	int ind;
	t_op op;

	ind = ft_stackelmind(ps->b.stack, ft_stackfind(ps->b.stack, "max"));
	if (ind > ps->b.len / 2)
	{
		op = rrb;
		ind = ps->b.len - ind;
	}
	else
		op = rb;
	while (ind-- != 0)
		apply_step(ps, op);
}

void	sort(t_ps *ps)
{
	apply_step(ps, pb);
	apply_step(ps, pb);
	while (ps->a.len != 0)
	{
		rank(ps);
		best(ps);
	}
	reset(ps);
	while (ps->b.len != 0)
		apply_step(ps, pa);
}
