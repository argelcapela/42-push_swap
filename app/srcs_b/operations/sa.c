/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/13 20:50:46 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

/* sa:
		 - swap the first 2 elements at the top of stack a.
		 - [0] = 1 and [1] = 33 when we swap we have: [0] = 33 and [1] = 1 */

void	sa(t_push_swap *ps)
{
	int	tmp;

	if (ps->a_size >= 2)
	{
		tmp = ps->a->value;
		ps->a->value = ps->a->next->value;
		ps->a->next->value = tmp;
	}
}
