/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   straight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:05:07 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/22 15:32:16 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_dblist	*get_oplist(void)
{
	char		*opstr;
	t_op		op;
	t_dblist	*oplist;
	int			ret;

	opstr = NULL;
	oplist = NULL;
	while (1)
	{
		ret = get_next_line(0, &opstr);
		if (ft_strequ(opstr, "done") || ret < 1)
			break ;
		op = convert_op(opstr);
		ft_lstdbadd(&oplist, ft_lstdbnew(opstr, op));
		ft_strdel(&opstr);
	}
	ft_strdel(&opstr);
	return (oplist);
}

void			straight(t_ps *ps)
{
	t_dblist *oplist;

	oplist = get_oplist();
	ft_lstdbtotop(&oplist);
	while (oplist != NULL)
	{
		apply_op(ps, oplist->n);
		if (oplist->next == NULL)
			break ;
		oplist = oplist->next;
	}
	ft_lstdbtotop(&oplist);
	ft_lstdbdel(&oplist);
}

void			debug(t_ps *ps)
{
	char		*opstr;
	t_op		op;
	int			ret;

	opstr = NULL;
	ft_putendl_cl("Init", CL(m));
	print_stacks(ps);
	while (1)
	{
		ret = get_next_line(0, &opstr);
		if (ft_strequ(opstr, "done") || ret < 1)
			break ;
		op = convert_op(opstr);
		apply_op(ps, op);
		ft_putchar('\t');
		ft_putendl_cl(opstr, CL(r));
		print_stacks(ps);
		ft_strdel(&opstr);
	}
	ft_strdel(&opstr);
}
