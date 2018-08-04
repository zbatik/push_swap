/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   straight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:05:07 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/04 15:38:56 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dblist	*get_oplist(void)
{
	char		*op_str;
	t_op		op;
	t_dblist	*oplist;
	int			ret;

	oplist = NULL;
	while (1)
	{
		ret = get_next_line(0, &op_str);
		if (ft_strequ(op_str, "done") || ret < 1)
			break ;
		op = convert_op(op_str);
		ft_lstdbadd(&oplist, ft_lstdbnew(op_str, op));
		ft_strdel(&op_str);
	}
	ft_strdel(&op_str);
//	while (oplist)
//		oplist = oplist->prev;
	return (oplist);
}

void	straight(t_ps *ps)
{
	t_dblist *oplist;

	oplist = get_oplist();
	while (oplist != NULL)
	{
		apply_op(ps, oplist->n);
		oplist = oplist->prev;
	}
}

void	debug(t_ps *ps)
{
	char		*op_str;
	t_op		op;
	int			ret;

	while (1)
	{
		ret = get_next_line(0, &op_str);
		if (ft_strequ(op_str, "done") || ret < 1)
			break;
		op = convert_op(op_str);
		apply_op(ps, op);
		ft_putchar('\t');
		ft_putendl_cl(op_str, CL(r));
		print_stacks(ps);
		ft_strdel(&op_str);
	}
	ft_strdel(&op_str);
//	while (oplist)
//		oplist = oplist->prev;
}
