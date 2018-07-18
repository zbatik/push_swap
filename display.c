/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:29:12 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/18 20:30:19 by zbatik           ###   ########.fr       */
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

/*
void	print_stacks(t_ps ps);
{
	int i;
	
	i = 0;
	while (i < ft_max(ps->len.a, ps->len.b))*/
