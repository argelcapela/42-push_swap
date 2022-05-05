/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/05 16:28:44 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* ss: Exeutes sa and sb at the same time. */

void	ss(t_push_swap *ps)
{
	sa(ps);
	sb(ps);
	ft_putstr_fd("ss\n", 1);
}
