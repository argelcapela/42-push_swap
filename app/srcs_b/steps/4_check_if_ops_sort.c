/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_check_if_ops_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/14 21:23:40 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	check_if_ops_sort(t_push_swap *ps)
{
	t_dll	*tmp;

	tmp = ps->a;
	if (ft_dll_is_sorted(tmp) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
