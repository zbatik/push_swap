/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:24:11 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/06 17:19:52 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 


static void put_error(char *err)
{
	ft_puterror(err);
	exit(-1);
}	

static int	ft_isint(char *in)
{
	char	*n;
	int		cmp;

	n = ft_itoa(ft_atoi(in));
	cmp = ft_strequ(n, in);
	ft_strdel(&n);
	if (cmp)
		return (1);	
	else
		return (0);
}

static int	check_dup(t_ps *ps, char *in)
{
	t_stack	*aa;
	int		n;

	n = ft_atoi(in);
	aa = ps->stack.a;
	while (aa)
	{
		if (aa->n == n)
			return (1);
	aa = aa->next;
	}
	return (0);
}

int			check_input(t_ps *ps, char *in)
{
	ps->file = 0;	

	if (!ft_isnumber(in))
		put_error("Error: input contains non-numbers");
	if (!ft_isint(in))
		put_error("Error: input contains non-integers");
	if (check_dup(ps, in))
		put_error("Error: input contains duplicates");
	return (ft_atoi(in));
}
