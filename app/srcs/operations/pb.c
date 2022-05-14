/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/13 23:22:56 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* pb: Take the first element at the top of a and put it at the top of a.
Do nothing if a is empty. */

void	pb(t_push_swap *ps)
{
	t_dll	*tmp;

	tmp = ps->b;
	if (ps->a == NULL && ps->b == NULL)
		return ;
	else if (ps->a == NULL)
		return ;
	else if (tmp == NULL)
	{
		tmp = ps->a;
		ps->a = ps->a->next;
		ps->b = tmp;
		tmp->next = NULL;
		tmp->previous = NULL;
	}
	else
	{
		tmp = ps->a;
		ps->a = ps->a->next;
		ps->b->previous = tmp;
		tmp->next = ps->b;
		ps->b = tmp;
		ps->a->previous = NULL;
		ps->a->next->previous = ps->a;
	}
	ps->a_size--;
	ps->b_size++;
	ft_dll_op_add_back(ps, "pb");
}
