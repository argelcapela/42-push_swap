/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/05 16:28:39 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* sa:
		 - swap the first 2 elements at the top of stack a.
		 - [0] = 1 and [1] = 33 when we swap we have: [0] = 33 and [1] = 1 */

void	sa(t_push_swap *ps)
{
	int	tmp;

	if (ft_dll_size(ps->a) <= 1)
		return ;
	tmp = ps->a->value;
	ps->a->value = ps->a->next->value;
	ps->a->next->value = tmp;
	ft_putstr_fd("sa\n", 1);
}
