/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:00:46 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/30 11:53:58 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dblist	*get_oplist(void)
{
	char		*op_str;	
	t_op		op;
	t_dblist	*oplist;

	oplist = NULL;
	while (1)	
	{
		get_next_line(0, &op_str);
		if (ft_strequ(op_str, "done"))
		{
			free(op_str);
			break;
		}
		op = convert_op(op_str);
		ft_lstdbadd(&oplist, ft_lstdbnew(op_str, op));
		free(op_str);
	}
//	while (oplist)
//		oplist = oplist->prev;
	return (oplist);
}

int	main(int c, char **v)
{
	t_ps *ps;
	t_dblist *oplist;

	if (c < 2)
		return (0);
	ps = init_ps(c - 1, v + 1);
	oplist = get_oplist();
	while (oplist != NULL)
	{
		apply_op(ps, oplist->n);
		oplist = oplist->prev;
	}
	if (is_assending(ps))
		ft_putendl_cl("OK", g);
	else
		ft_putendl_cl("KO", r);
}
