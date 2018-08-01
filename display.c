/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:29:12 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/01 10:53:17 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	int i;

	i = -1;
	while (stack)
	{
		ft_putnbr(stack->n);
		ft_putchar('\n');
		stack = stack->next;
	}
}

static void	print_lables(t_ps *ps)
{
	ft_putchar('A');
	ft_putchar_cl(':', g);
	ft_putnbr_cl(ps->length.a, g);
	ft_putstr("\t\t");
	ft_putchar('B');
	ft_putchar_cl(':', g);
	ft_putnbr_cl(ps->length.b, g);
	ft_putchar('\n');
}

void	print_stacks(t_ps *ps)
{
	t_stack	*a;
	t_stack	*b;

	a = ps->stack.a;
	b = ps->stack.b;
	print_lables(ps);
	while (a != NULL || b != NULL)
	{
		if (a != NULL)
		{
			ft_putnbr_cl(a->n, y);
			a = a->next;
		}
		ft_putstr("\t\t");
		if (b != NULL)
		{	
			ft_putnbr_cl(b->n, c);
			b = b->next;
		}
		ft_putchar('\n');
	}
}

void	print_results(t_ps *ps)
{
	if (is_assending(ps))
		ft_putendl_cl("OK", g);
	else
		ft_putendl_cl("KO", r);
}
