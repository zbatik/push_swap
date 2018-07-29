/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 13:56:03 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/29 15:54:25 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op	convert_op(char *op)
{
	if (!ft_strcmp(op, "sa"))
		return (sa);
	else if (!ft_strcmp(op, "sb"))
		return (sb);
	else if (!ft_strcmp(op, "ss"))
		return (ss);
	else if (!ft_strcmp(op, "pa"))
		return (pa);
	else if (!ft_strcmp(op, "pb"))
		return (pb);
	else if (!ft_strcmp(op, "ra"))
		return (ra);
	else if (!ft_strcmp(op, "rb"))
		return (rb);
	else if (!ft_strcmp(op, "rr"))
		return (rr);
	else if (!ft_strcmp(op, "rra"))
		return (rra);
	else if (!ft_strcmp(op, "rrb"))
		return (rrb);
	else if (!ft_strcmp(op, "rrr"))
		return (rrr);
	return (error);
}
