/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:03:39 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/17 16:26:53 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*init_ps(int count, char **input)
{
	int	i;
	t_ps	ps;
	t_stack tmp;

	ps = (t_ps*)malloc(sizeof(t_ps));
	
	ps->a = ft_stnew(ft_atoi(input[i]));
	ps->bottom.a = t_ps->a;
	ps->length.a = count;

	ps->b = NULL;
	ps->bottom.b = NULL;
	pos->length.b = 0;
	i = 1;
	while (i < count)
	{
		tmp = ft_stnew(ft_atoi(input[i]));
		ft_stadd(&ps->a, tmp, ps->bottom.a);
	}
	return(ps
}
