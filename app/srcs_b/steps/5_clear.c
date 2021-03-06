/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_clear.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:50:38 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/13 17:54:50 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	clear(t_push_swap *ps)
{
	ft_dll_free(ps->a);
	ft_free_ptr((void *) &(ps->b));
	ft_free_ptr((void *) &ps);
}
