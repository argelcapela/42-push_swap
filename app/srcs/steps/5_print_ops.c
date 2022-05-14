/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_print_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/14 22:37:54 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_ops(t_push_swap *ps)
{
	t_dll	*tmp;

	tmp = ps->ops;
	while (ps->ops_size > 0)
	{
		ft_printf("%s\n", tmp->op_name);
		tmp = tmp->next;
		ps->ops_size--;
	}
}
