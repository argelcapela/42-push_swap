/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_clear.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:50:38 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/14 22:35:45 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	clear(t_push_swap *ps)
{
	ft_dll_free(ps->a);
	ft_dll_free(ps->b);
	if (ps->ops)
		ft_dll_free(ps->ops);
	ft_free_ptr((void *) &ps);
}
