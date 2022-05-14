/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_op_add_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/13 23:21:18 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_dll_op_add_back(t_push_swap *ps, char *op_name)
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
	ft_dll_last(ps->ops)->next = NULL;
	ps->ops_size++;
}
