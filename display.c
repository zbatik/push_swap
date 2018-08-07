/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:29:12 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/07 10:45:42 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_lables(t_ps *ps)
{
	ft_putchar('A');
	ft_putchar_cl(':', CL(g));
	ft_putnbr_cl(ps->a.len, CL(g));
	ft_putstr("\t\t");
	ft_putchar('B');
	ft_putchar_cl(':', CL(g));
	ft_putnbr_cl(ps->b.len, CL(g));
	ft_putchar('\n');
}

void		print_stacks(t_ps *ps)
{
	t_stack	*a;
	t_stack	*b;

	a = ps->a.stack;
	b = ps->b.stack;
	print_lables(ps);
	while (a != NULL || b != NULL)
	{
		if (a != NULL)
		{
			ft_putnbr_cl(a->n, CL(y));
			a = a->next;
		}
		ft_putstr("\t\t");
		if (b != NULL)
		{
			ft_putnbr_cl(b->n, CL(c));
			b = b->next;
		}
		ft_putchar('\n');
	}
}

void		print_result(t_ps *ps)
{
	if (is_assending(ps->a.stack, ps->a.len) && ps->b.len == 0)
		ft_putendl_cl("OK", g);
	else
		ft_putendl_cl("KO", r);
}
