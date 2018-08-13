/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:13:27 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/13 18:54:21 by zbatik           ###   ########.fr       */
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

		t_stack		*best_ind(t_stack *a)
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

static void	best(t_ps *ps)
{
	t_stack	*node;

	node = best_ind(ps->a.stack);
	while (node->a_rank != 0)
	{
		if (node->a_dir == ra && node->b_dir == rb && node->b_rank != 0)
		{
			apply_step(ps, rr);
			node->a_rank -= 1;
			node->b_rank -= 1;
		}
		else if (node->a_dir == rra && node->b_dir == rrb && node->b_rank != 0)
		{
			apply_step(ps, rrr);
			node->a_rank -= 1;
			node->b_rank -= 1;
		}
		else
		{
			apply_step(ps, node->a_dir);
			node->a_rank -= 1;
		}
	}
	while(node->b_rank != 0)
	{
		apply_step(ps, node->b_dir);
		node->b_rank -= 1;
	}
	apply_step(ps, pb);
}

static void	reset(t_ps *ps)
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
	if (is_assending(ps->a.stack, ps->a.len))
		return ;
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
