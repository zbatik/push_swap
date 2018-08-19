/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:24:11 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/19 13:05:41 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_error(char *err)
{
	ft_puterror(err);
	exit(-1);
}

static int	ft_isint(char *in)
{
	int		len;
	char	str_int[11];
	int		sign;
	int		i;

	sign = 0;
	if (*in == '-')
		sign = 1;
	ft_strcpy(str_int, "2147483647");
	str_int[9] += sign;
	len = ft_strlen(in + sign);
	if (len > 10)
		return (0);
	if (len < 10)
		return (1);
	i = sign - 1;
	while (in[++i])
	{
		if (in[i] > str_int[i - sign])
			return (0);
	}
	return (1);
}

static int	check_dup(t_ps *ps, char *in)
{
	t_stack	*aa;
	int		n;

	n = ft_atoi(in);
	aa = ps->a.stack;
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
	if (!ft_isnumber(in))
		put_error("Error: input contains non-numbers");
	if (!ft_isint(in))
		put_error("Error: input contains non-integers");
	if (check_dup(ps, in))
		put_error("Error: input contains duplicates");
	ps->debug = 0;
	return (ft_atoi(in));
}

int			is_assending(t_stack *stack, int len)
{
	int		i;

	i = -1;
	while (++i < len - 1)
	{
		if (stack->n > stack->next->n)
			return (0);
		stack = stack->next;
	}
	return (1);
}
