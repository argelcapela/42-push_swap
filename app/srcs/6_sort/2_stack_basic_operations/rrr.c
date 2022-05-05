/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/05 16:28:37 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* rrr: - Executes ra and rb at the same time. */

void	rrr(t_push_swap *ps)
{
	rra(ps);
	rrb(ps);
	ft_putstr_fd("rrr\n", 1);
}
