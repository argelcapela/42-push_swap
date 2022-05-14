/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_receive_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/14 03:12:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int	check_ops_input(char *op)
{
	if (ft_strncmp(op, "ra", 2) == 0 || \
		ft_strncmp(op, "rb", 2) == 0 || \
		ft_strncmp(op, "rr", 2) == 0 || \
		ft_strncmp(op, "rra", 3) == 0 || \
		ft_strncmp(op, "rrb", 3) == 0 || \
		ft_strncmp(op, "rrr", 3) == 0 || \
		ft_strncmp(op, "sa", 2) == 0 || \
		ft_strncmp(op, "sb", 2) == 0 || \
		ft_strncmp(op, "ss", 2) == 0 || \
		ft_strncmp(op, "pa", 2) == 0 || \
		ft_strncmp(op, "pb", 2) == 0
	)
		return (0);
	else
	{
		ft_printf("Error\n");
		return (1);
	}
}

int	receive_ops(t_push_swap *ps)
{
	char	*op;

	op = get_next_line(0);
	while (op && 1)
	{
		if (check_ops_input(op) == 0)
			ft_dll_op_add_back(ps, op);
		else
			return (1);
		op = get_next_line(0);
	}
	return (0);
}
