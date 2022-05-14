/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_execute_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/14 17:31:59 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	execute_op(t_push_swap *ps, char *op)
{
	if (ft_strncmp(op, "rrr", 3) == 0)
		rrr(ps);
	else if (ft_strncmp(op, "rra", 3) == 0)
		rra(ps);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		rrb(ps);
	else if (ft_strncmp(op, "rr", 2) == 0)
		rr(ps);
	if (ft_strncmp(op, "sa", 2) == 0)
		sa(ps);
	else if (ft_strncmp(op, "sb", 2) == 0)
		sb(ps);
	else if (ft_strncmp(op, "ss", 2) == 0)
		ss(ps);
	else if (ft_strncmp(op, "ra", 2) == 0)
		ra(ps);
	else if (ft_strncmp(op, "rb", 2) == 0)
		rb(ps);
	else if (ft_strncmp(op, "pa", 2) == 0)
		pa(ps);
	else if (ft_strncmp(op, "pb", 2) == 0)
		pb(ps);
}

int	check_ops_input(char *op)
{
	if (ft_strncmp(op, "rrr\n", 4) == 0 
		|| ft_strncmp(op, "rra\n", 4) == 0 
		|| ft_strncmp(op, "rrb\n", 4) == 0 
		|| ft_strncmp(op, "rr\n", 3) == 0 
		|| ft_strncmp(op, "ra\n", 3) == 0 
		|| ft_strncmp(op, "rb\n", 3) == 0 
		|| ft_strncmp(op, "sa\n", 3) == 0 
		|| ft_strncmp(op, "sb\n", 3) == 0 
		|| ft_strncmp(op, "ss\n", 3) == 0 
		|| ft_strncmp(op, "pa\n", 3) == 0 
		|| ft_strncmp(op, "pb\n", 3) == 0
	)
		return (0);
	else
	{
		ft_printf("Error\n");
		return (1);
	}
}

void	execute_ops(t_push_swap *ps)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		if (check_ops_input(op) == 0)
			execute_op(ps, op);
		else
		{
			clear(ps);
			exit(1);
		}
		op = get_next_line(0);
	}
}