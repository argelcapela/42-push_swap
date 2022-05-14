/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/13 16:58:20 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	op_add_back(t_push_swap *ps, char *op_name)
{
	t_dll *op;
	t_dll *last;

	op = (t_dll *) malloc(sizeof(t_dll));
	op->op_name = op_name;
	if (ps->ops_size)
	{
		last = ft_dll_last(ps->ops);
		last->next = op;
		op->previous = last;
	}
	else
		ps->ops = op;
	ps->ops_size++;
}
