/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:39:46 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/29 17:51:33 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	apply_op1(t_ps *ps, t_op op)
{
	if (op == sa)
		swap(&ps->stack.a, ps->length.a);
	else if (op == sb)
		swap(&ps->stack.b, ps->length.b);
	else if (op == sb)
	{	
		swap(&ps->stack.a, ps->length.a);
		swap(&ps->stack.b, ps->length.b);
	}
	else if (op == sb)
		push(&ps->stack.b, &ps->stack.a, &ps->length.b, &ps->length.a);
	else if (op == sb)
		push(&ps->stack.a, &ps->stack.b, &ps->length.a, &ps->length.b);
	else if (op == sb)
		rotate(&ps->stack.a, ps->length.a);
	else if (op == sb)
		rotate(&ps->stack.b, ps->length.b);
}

void	apply_op2(t_ps *ps, t_op op)
{
	if (op == sb)
	{
		rotate(&ps->stack.a, ps->length.a);
		rotate(&ps->stack.b, ps->length.b);
	}
	else if (op == sb)
		rrotate(&ps->stack.a, ps->length.a);
	else if (op == sb)
		rrotate(&ps->stack.b, ps->length.b);
	else if (op == sb)
	{
		rrotate(&ps->stack.a, ps->length.a);
		rrotate(&ps->stack.b, ps->length.b);
	}
	else if (op == sb)
	{
		ft_puterror("Invaild Operation");
		exit(0);
	}
}

void	apply_op(t_ps *ps, t_op op)
{
	apply_op2(t_ps *ps, t_op op)
	apply_op1(t_ps *ps, t_op op)
}
