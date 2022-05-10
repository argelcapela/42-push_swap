/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/05 16:28:19 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* pa: Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */

void	pa(t_push_swap *ps)
{
	t_dll	*tmp;

	tmp = ps->a;
	if (ps->a == NULL && ps->b == NULL)
		return ;
	else if (ps->b == NULL)
		return ;
	else if (tmp == NULL)
	{
		tmp = ps->b;
		ps->b = ps->b->next;
		ps->a = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp = ps->b;
		ps->b = ps->b->next;
		tmp->next = ps->a;
		ps->a = tmp;
	}
	ft_putstr_fd("pa\n", 1);
}