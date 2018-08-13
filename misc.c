/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:36:22 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/13 18:44:05 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean(t_ps **ps)
{
	ft_stackdel(&(*ps)->a.stack);
	(*ps)->a.stack = NULL;
	ft_stackdel(&(*ps)->b.stack);
	(*ps)->b.stack = NULL;
	free(*ps);
	*ps = NULL;
}
