/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/13 23:22:51 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* ra: - The first element of stack a becomes the last one. */

void	ra(t_push_swap *ps)
{
	t_dll	*first;
	t_dll	*second;
	t_dll	*last;

	if (ps->a_size >= 2)
	{
		first = ps->a;
		second = ps->a->next;
		last = ps->a;
		while (last->next != NULL)
			last = last->next;
		last->next = first;
		first->previous = last;
		first->next = NULL;
		ps->a = second;
		ps->a->previous = NULL;
		ft_dll_op_add_back(ps, "ra");
	}
}
