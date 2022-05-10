/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/05 16:28:32 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* rra: - The last element of stack a becomes the first one. */

void	rra(t_push_swap *ps)
{
	t_dll	*first;
	t_dll	*before_last;
	t_dll	*last;

	if (ps->a == NULL)
		return ;
	first = ps->a;
	last = ps->a;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	last->next = first;
	before_last->next = NULL;
	ps->a = last;
	ft_putstr_fd("rra\n", 1);
}