/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/13 17:54:36 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<checker.h>

void	two(t_push_swap *ps)
{
	t_dll	*n1;
	t_dll	*n2;

	if (ft_dll_size(ps->a) != 2)
		return ;
	n1 = ps->a;
	n2 = ps->a->next;
	if (n1->value > n2->value)
		sa(ps);
}

void	two2(t_push_swap *ps)
{
	t_dll	*n1;
	t_dll	*n2;

	if (ft_dll_size(ps->b) < 2)
		return ;
	n1 = ps->b;
	n2 = ps->b->next;
	if (n1->value > n2->value)
		sb(ps);
}
