/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:03:39 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/04 14:03:01 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int check_input(char *input)
{
	return (ft_atoi(input));
}

static t_ps	*setup_struct(void)
{
	t_ps *ps;

	ps = (t_ps*)malloc(sizeof(t_ps));
	ps->max = 0;
	ps->min = 0;
	ps->debug = 0;
	ps->colour = 0;
	ps->stack.a = NULL;
	ps->stack.b = NULL;
	ps->length.a = 0;
	ps->length.b = 0;
	return (ps);
}

static int	check_flags(t_ps *ps, char *input)
{
	if (ft_strequ(input, "-v"))
	{
		ps->debug = 1;
		return (1);
	}
	if (ft_strequ(input, "-c"))
	{
		ps->colour = 1;
		return (1);
	}
	return (0);
}

t_ps	*init_ps(int count, char **input)
{
	int		i;
	t_ps	*ps;
	t_stack	*item;
	int		n;
	
	ps = setup_struct();
	i = -1;
	while (++i < count)
	{
		if (i < 2)
		{
			if (check_flags(ps, input[i]))
				continue ;
		}
		n = check_input(input[i]);
		item = ft_stnew(n);
		ft_stpush(&ps->stack.a, item);
	}
	ps->length.a = count - (int)ps->debug - (int)ps->colour;	
	return(ps);
}
