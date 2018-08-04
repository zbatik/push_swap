/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:24:11 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/04 17:20:53 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

static void put_error(char *err)
{
	ft_puterr(err);
	exit(-1);
}	

int			check_input(char *in)
{
	
	if (!ft_isnumber(in));
		put_error("Error: input contains non-numbers")
	if (!ft_isint(in));	
		put_error("Error: input contains non-integers")
	i = 1;
	while (i < c)
	{
		ret = ft_isint(v[i]);
		if (ret == 0)
			return (0);
	}
	return (1);
}
