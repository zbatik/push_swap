/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:00:46 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/22 15:37:19 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int c, char **v)
{
	t_ps *ps;

	if (c < 2)
		return (0);
	ps = init_ps(c - 1, v + 1);
	if (ps->debug)
		debug(ps);
	else
		straight(ps);
	print_result(ps);
	clean(&ps);
	while (1)
		;
}
