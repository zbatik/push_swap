/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:29:12 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/18 20:57:23 by zack             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, int len)
{
	int i;

	i = -1;
	while (++i < len)
	{
		ft_putnbr(stack->n);
		stack = stack->prev;
		ft_putchar('\n');
	}
}

void	post_error(void)
{
	write(2, "Error\n", 6);
}


void	print_stacks(t_ps *ps)
{
	int i;

	ft_putendl("A\t\tB\n");
	i = -1;
	while (++i < ft_max(ps->length.a, ps->length.b))
	{
		if (i < ps->length.a)
		{
			ft_putnbr(ps->stack.a->n);
			ps->stack.a = ps->stack.a->prev;
		}
		else
			ft_putchar('\t');
		ft_putstr("\t\t");
		if (i < ps->length.b)
		{	
			ft_putnbr(ps->stack.b->n);
			ps->stack.a = ps->stack.a->prev;
		}
		ft_putchar('\n');
	}
}

		
