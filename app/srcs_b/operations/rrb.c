/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/13 18:19:29 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

/* rrb: - The last element of stack b becomes the first one. */

void	rrb(t_push_swap *ps)
{
	t_dll	*first;
	t_dll	*before_last;
	t_dll	*last;

	if (ps->b_size >= 2)
	{
		first = ps->b;
		last = ps->b;
		while (last->next != NULL)
		{
			before_last = last;
			last = last->next;
		}
		last->next = first;
		before_last->next = NULL;
		ps->b = last;
		last->previous = NULL;
	}
}
