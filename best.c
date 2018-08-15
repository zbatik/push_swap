/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:05:46 by event             #+#    #+#             */
/*   Updated: 2018/08/15 14:15:06 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*best_ind(t_stack *a)
{
	int		score;
	t_stack	*top;

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

static void		adjust(t_ps *ps, t_stack *node, t_op op)
{
	apply_step(ps, op);
	node->a_rank -= 1;
	node->b_rank -= 1;
}

void			best(t_ps *ps)
{
	t_stack	*node;

	node = best_ind(ps->a.stack);
	while (node->a_rank != 0)
	{
		if (node->a_dir == ra && node->b_dir == rb && node->b_rank != 0)
			adjust(ps, node, rr);
		else if (node->a_dir == rra && node->b_dir == rrb && node->b_rank != 0)
			adjust(ps, node, rrr);
		else
		{
			apply_step(ps, node->a_dir);
			node->a_rank -= 1;
		}
	}
	while (node->b_rank != 0)
	{
		apply_step(ps, node->b_dir);
		node->b_rank -= 1;
	}
	apply_step(ps, pb);
}
