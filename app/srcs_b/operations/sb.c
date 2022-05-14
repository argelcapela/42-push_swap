/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/13 18:19:39 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

/* sb:
		 - swap the first 2 elements at the top of stack b.
		 - [0] = 1 and [1] = 33 when we swap we have: [0] = 33 and [1] = 1 */

void	sb(t_push_swap *ps)
{
	int	tmp;

	if (ps->b_size >= 2)
	{
		tmp = ps->b->value;
		ps->b->value = ps->b->next->value;
		ps->b->next->value = tmp;
	}
}
