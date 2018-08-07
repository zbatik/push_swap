/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:03:39 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/07 11:18:38 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ps	*setup_struct(void)
{
	t_ps *ps;

	ps = (t_ps*)malloc(sizeof(t_ps));
	ps->a.max = 0;
	ps->b.max = 0;
	ps->a.min = 0;
	ps->b.min = 0;
	ps->debug = 0;
	ps->colour = 0;
	ps->a.stack = NULL;
	ps->b.stack = NULL;
	ps->a.len = 0;
	ps->b.len = 0;
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

static void	fmt_input(int *c, char ***input)
{
	char	**tmp;
	int		i;

	i = 0;
	*input = ft_strsplit(**input, ' ');
	tmp = *input;
	while (tmp[i])
		i++;
	*c = i;
}

t_ps		*init_ps(int count, char **input)
{
	int		i;
	t_ps	*ps;
	t_stack	*item;
	int		n;

	ps = setup_struct();
	if (count == 1)
		fmt_input(&count, &input);
	i = count;
	while (--i >= 0)
	{
		if (i < 2)
		{
			if (check_flags(ps, input[i]))
				continue ;
		}
		n = check_input(ps, input[i]);
		item = ft_stacknew(n);
		ft_stackpush(&ps->a.stack, item);
	}
	ps->a.len = count - (int)ps->debug - (int)ps->colour;
	set_extremes(ps);
	return (ps);
}
