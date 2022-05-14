/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort.c                                 			:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:45:26 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/04 22:47:46 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort(t_push_swap *ps)
{
	if (ft_dll_is_sorted(ps->a) == 1)
		return ;
	if (ps->a_size == 2)
		two(ps);
	else if (ps->a_size == 3)
		three(ps);
	else if (ps->a_size > 3 && ps->a_size <= 5)
		five(ps);
	else
		fit_sort(ps);
}
