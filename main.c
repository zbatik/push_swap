/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:00:46 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/01 12:30:53 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dblist	*get_oplist(int fd)
{
	char		*op_str;	
	t_op		op;
	t_dblist	*oplist;
	int			ret;

	oplist = NULL;
	while (1)	
	{
		ret = get_next_line(fd, &op_str);
		if (ft_strequ(op_str, "done") || ret < 0)
		{
			ft_strdel(&op_str);
			break;
		}
		op = convert_op(op_str);
		ft_lstdbadd(&oplist, ft_lstdbnew(op_str, op));
		ft_strdel(&op_str);
	}
//	while (oplist)
//		oplist = oplist->prev;
	return (oplist);
}

int	main(int c, char **v)
{
	t_ps		*ps;
	t_dblist	*oplist;
	int			fd;

	fd = 0;
	if (c < 2)
		return (0);
/*	
	if (c == 2)
	{
		fd = open(v[1], O_RDONLY);
		if (fd > 0)
		{
			char	*input;
			int		ret;
			ret = get_next_line(fd, &input);
			if (ret > 0)
				v = ft_strsplit(input, ' ');
			ft_strdel(&input);
		}
	}
*/	
	ps = init_ps(c - 1, v + 1);
	oplist = get_oplist(fd);
	while (oplist != NULL)
	{
		apply_op(ps, oplist->n);
		oplist = oplist->prev;
	}
	print_results(ps);
}
