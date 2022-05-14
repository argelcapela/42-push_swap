/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/13 23:22:48 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* rb: - The first element of stack b becomes the last one. */

void	rb(t_push_swap *ps)
{
	t_dll	*first;
	t_dll	*second;
	t_dll	*last;

	if (ps->b_size >= 2)
	{
		first = ps->b;
		second = ps->b->next;
		last = ps->b;
		while (last->next != NULL)
			last = last->next;
		last->next = first;
		first->previous = last;
		first->next = NULL;
		ps->b = second;
		ps->b->previous = NULL;
		ft_dll_op_add_back(ps, "rb");
	}
}
