/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_execute_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/13 20:55:10 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	execute_op(t_push_swap *ps, char *op)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		sa(ps);
	else if (ft_strncmp(op, "sb", 2) == 0)
		sb(ps);
	else if (ft_strncmp(op, "ra", 2) == 0)
		ra(ps);
	else if (ft_strncmp(op, "rb", 2) == 0)
		rb(ps);
	else if (ft_strncmp(op, "rra", 3) == 0)
		rra(ps);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		rrb(ps);
	else if (ft_strncmp(op, "pa", 2) == 0)
		pa(ps);
	else if (ft_strncmp(op, "pb", 2) == 0)
		pb(ps);
}

void	execute_ops(t_push_swap *ps)
{
	t_dll *tmp;

	tmp = ps->ops;
	while (tmp != NULL)
	{
		execute_op(ps, tmp->op_name);
		tmp = tmp->next;
	}
}
