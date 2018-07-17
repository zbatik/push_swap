/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:01:19 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/17 14:57:25 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stnew(int n)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	new->n = n;
	new->next = new;
	new->prev = new;
	return (new);
}

void	ft_stpush(t_stack **head, t_stack *in, t_stack *bottom)
{
	in->prev = *head;
	in->next = bottom;
	bottom->prev = in;
	*head = in;
}
