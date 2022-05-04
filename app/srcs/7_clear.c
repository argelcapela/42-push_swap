/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_clear.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:50:38 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/04 22:48:17 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	free_stack(t_dll *stack)
{
	t_dll	*free;

	while (stack != NULL)
	{
		free = stack;
		stack = stack->next;
		ft_free_ptr((void *) &free);
	}
}

void	clear_app(t_push_swap *ps)
{
	free_stack(ps->a);
	ft_free_ptr((void *) &(ps->b));
	ft_free_ptr((void *) &ps);
}
