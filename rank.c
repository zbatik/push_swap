/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 18:46:46 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/15 14:31:22 by event            ###   ########.fr       */
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

static int	b_rank_check(t_stack *b, int b_len, t_stack *a)
{
	int count;

	count = 0;
	while (b->next)
	{
		count++;
		if (a->n < b->n && a->n > b->next->n)
		{
			if (count > b_len / 2)
			{
				a->b_dir = rrb;
				return (b_len - count);
			}
			else
			{
				a->b_dir = rb;
				return (count);
			}
		}
		b = b->next;
	}
	a->b_dir = rb;
	return (0);
}

static int	b_rank_elm(t_stack *a, t_group *b)
{
	if (a->n > ft_stackfind(b->stack, "max"))
	{
		a->b_dir = rb;
		return (ft_stackelmind(b->stack, ft_stackfind(b->stack, "max")));
	}
	if (a->n < ft_stackfind(b->stack, "min"))
	{
		a->b_dir = rb;
		return (ft_stackelmind(b->stack, ft_stackfind(b->stack, "max")));
	}
	return (b_rank_check(b->stack, b->len, a));
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
