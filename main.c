/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:00:46 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/28 13:59:29 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_oplist	get_oplist(void)
{	
	t_op op;
	t_oplist oplist;
	
	while (1)	
	{
		get_next_line(0, &op_str);
		if (ft_strequ(op_str, "done"))
		{
			free(op_str);
			break;
		}
		op = convert_op(op_str);
		store_op(op);
		free(op_str);
	}
}

int	main(int c, char **v)
{
	t_ps *ps;
	char *op_str;

	if (c < 2)
		return (0);
	ps = init_ps(c - 1, v + 1);
	get_oplist();
}
