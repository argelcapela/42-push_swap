/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_sort_3_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/04 01:53:56 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_3_numbers(t_push_swap *ps)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = ps->a->value;
	n2 = ps->a->next->value;
	n3 = ps->a->next->next->value;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(ps);
	else if (n1 > n2 && n2 > n3 && n1 > n3)
	{
		sa(ps);
		rra(ps);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(ps);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		sa(ps);
		ra(ps);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra(ps);
}
