/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:00:46 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/17 12:44:20 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack *a;
	t_stack *bottom;
	t_stack *tmp;

	a = ft_stnew(2);
	bottom = a;
	tmp = ft_stnew(8);
	ft_stpush(&a, tmp, bottom);
	tmp = ft_stnew(4);
	ft_stpush(&a, tmp, bottom);
	tmp = ft_stnew(-1);
	ft_stpush(&a, tmp, bottom);
	tmp = ft_stnew(18);
	ft_stpush(&a, tmp, bottom);
	print_stack(a, 5);	
}
