/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:27:01 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/14 00:03:23 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* move to stack b dividing in two groups
 except the biggest value node, and the lower value node */

void	move_to_b(t_push_swap *ps)
{
	int	max;

	max = ps->a_size - 1;
	while (ps->a_size > 2)
	{
		if (ps->a->index == 0 || ps->a->index == max)
			ra(ps);
		else
			pb(ps);
		if ((ps->b_size >= 2) && ps->b->value > (max / 2))
			rb(ps);
		if (ft_dll_is_sorted(ps->a))
			break ;
	}
}
