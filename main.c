/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:00:46 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/04 15:04:13 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int c, char **v)
{
	t_ps		*ps;
	//int			fd;

	//fd = 0;
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
	if (ps->debug)
		debug(ps);
	else
		straight(ps);
	print_result(ps);
}
