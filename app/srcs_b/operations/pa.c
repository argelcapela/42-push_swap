/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/14 22:24:38 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

/* pa: Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */

void	if_a_is_null(t_push_swap *ps, t_dll *tmp)
{
	tmp = ps->b;
	ps->b = ps->b->next;
	ps->a = tmp;
	tmp->next = NULL;
	tmp->previous = NULL;
}

void	pa(t_push_swap *ps)
{
	t_dll	*tmp;

	tmp = ps->a;
	if (!ps->b_size)
		return ;
	if (tmp == NULL)
		if_a_is_null(ps, tmp);
	else
	{
		tmp = ps->b;
		ps->b = ps->b->next;
		tmp->next = ps->a;
		ps->a = tmp;
	}
	ps->a_size++;
	ps->b_size--;
}
