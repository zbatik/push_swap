/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:03:39 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/27 14:14:22 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*init_ps(int count, char **input)
{
	int		i;
	t_ps	*ps;
	t_stack	*item;
	
	i = 0;
	ps = (t_ps*)malloc(sizeof(t_ps));
	ps->stack.a = ft_stnew(ft_atoi(input[i++]));
	ps->length.a = count;
	ps->stack.b = NULL;
	ps->length.b = 0;
	while (i < count)
	{
		item = ft_stnew(ft_atoi(input[i++]));
		ft_stpush(&ps->stack.a, item);
	}
	return(ps);
}
