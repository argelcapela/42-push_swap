/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_check_if_ops_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/13 20:48:45 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	check_if_ops_sort(t_push_swap *ps)
{
	if (ft_dll_is_sorted(ps->a) == 1)
		ft_printf("OK");
	else
		ft_printf("KO");
}
