/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:00:46 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/27 16:12:09 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int c, char **v)
{
	t_ps *ps;

	if (c < 2)
		return (0);
	ps = init_ps(c - 1, v + 1);

	print_stacks(ps);
	t_op op = sa;	
	ft_putendl_cl("sa", 'r');
	apply_op(ps, op);
	print_stacks(ps);

	ft_putendl_cl("sb", 'r');
	apply_op(ps, sb);
	print_stacks(ps);

	ft_putendl_cl("pb x 2", 'r');
	apply_op(ps, pb);
	apply_op(ps, pb);
	print_stacks(ps);

	ft_putendl_cl("sb", 'r');
	apply_op(ps, sb);
	print_stacks(ps);

	ft_putendl_cl("pa x 3", 'r');
	apply_op(ps, pa);
	apply_op(ps, pa);
	apply_op(ps, pa);
	print_stacks(ps);

	ft_putendl_cl("sa", 'r');
	apply_op(ps, sa);
	print_stacks(ps);

	ft_putendl_cl("rrb X2", 'r');
	apply_op(ps, rrb);
	apply_op(ps, rrb);
	print_stacks(ps);

	ft_putendl_cl("rra X3", 'r');
	apply_op(ps, rra);
	apply_op(ps, rra);
	apply_op(ps, rra);
	print_stacks(ps);

	ft_putendl_cl("ra", 'r');
	apply_op(ps, ra);
	print_stacks(ps);
	ft_putendl_cl("ra", 'r');
	apply_op(ps, ra);
	print_stacks(ps);
	ft_putendl_cl("ra", 'r');
	apply_op(ps, ra);
	print_stacks(ps);

}
