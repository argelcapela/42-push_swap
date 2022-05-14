/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/14 03:13:49 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* pa: Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */
	// else if (tmp == NULL)
	// {
	// 	tmp = ps->b;
	// 	ps->b = ps->b->next;
	// 	ps->a = tmp;
	// 	tmp->next = NULL;
	// }

void	pa(t_push_swap *ps)
{
	t_dll	*tmp;

	tmp = ps->a;
	if (ps->b_size)
	{
		tmp = ps->b;
		ps->b = ps->b->next;
		tmp->next = ps->a;
		ps->a = tmp;
		ps->a->next->previous = ps->a;
		ps->a->previous = NULL;
	}
	ps->a_size++;
	ps->b_size--;
	op_add_back(ps, "pa");
}
