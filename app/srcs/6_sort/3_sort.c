/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/04 01:51:56 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort(t_push_swap *ps)
{
	if (is_sorted(ps->a) == 1)
		return ;
	if (ps->stack_length == 2)
		sort_2_numbers(ps);
	else if (ps->stack_length == 3)
		sort_3_numbers(ps);
	else if (ps->stack_length > 3 && ps->stack_length <= 5)
		sort_5_numbers(ps);
	else
	{
		ps->group_size = ps->argc / 200 * 5 + 10;
		sort_more_than_5_numbers(ps);
	}
}
