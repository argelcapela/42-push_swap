/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_smaller_to_top.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:28:26 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/13 23:28:32 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	bring_smaller_to_top(t_push_swap *ps)
{
	t_dll	*tmp;
	int		i;

	i = 0;
	tmp = ps->a;
	while (tmp && tmp->index != (ps->a_size - 1))
	{
		i++;
		tmp = tmp->next;
	}
	while ((i + 1) > 0)
	{
		ra(ps);
		i--;
	}
}
