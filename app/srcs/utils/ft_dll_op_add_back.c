/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_op_add_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/14 01:34:58 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_dll_op_add_back(t_push_swap *ps, char *op_name)
{
	t_dll	*last;

	if (ps->ops == NULL)
	{
		ps->ops = (t_dll *) malloc(sizeof(t_dll));
		ps->ops->op_name = op_name;
		ps->ops->previous = NULL;
		ps->ops->next = NULL;
	}
	else
	{
		last = ft_dll_last(ps->ops);
		last->next = (t_dll *) malloc(sizeof(t_dll));
		last->next->previous = last;
		last->next->op_name = op_name;
		last->next->next = NULL;
	}
	ps->ops_size++;
}
