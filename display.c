/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:29:12 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/16 19:49:14 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_stack(t_stack stack, int len)
{
	int i;

	while (i < len)
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
