/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/14 16:04:54 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<push_swap.h>

/*
	This function calc how many rotations stack b needs
	until some specific node inside stack_b
	arrive the top, otherwise, be the first node.
*/
static void	calc_stack_b_rotations(t_push_swap *ps)
{
	t_dll	*b_iterator;

	ps->r_u_top_b = 0;
	b_iterator = ps->b;
	while (b_iterator->value != ps->b_node->value)
	{
		ps->r_u_top_b++;
		b_iterator = b_iterator->next;
	}
	if (ps->r_u_top_b > (ps->b_size / 2))
	{
		ps->tmp_n_op_b = (ps->b_size - ps->r_u_top_b);
		ps->tmp_op_b = "rrb";
	}
	else
	{
		ps->tmp_n_op_b = ps->r_u_top_b;
		ps->tmp_op_b = "rb";
	}
}

/*
	This function calculates how many rotations stack_a needs
	for when pa is executed, the stack_b first node, fits in
	the top of stack_a without messing up the sorting, otherwise,
	stack_b first node < stack_a first node and stack_b first
	node > node previous of stack_a first node

	r_u_top_b -> rotations until top stack_b

	r_u_f_a -> rotations until until fits stack_a without messing up it

*/

static void	calc_stack_a_rotations(t_push_swap *ps)
{
	t_dll	*a_iterator;

	ps->r_u_f_a = 0;
	a_iterator = ps->a;
	while (ps->r_u_f_a < ps->a_size)
	{
		if (a_iterator->index > ps->b_node->index && \
			ft_dll_prev_index(ps->a, a_iterator) < ps->b_node->index)
			break ;
		else
			ps->r_u_f_a++;
		a_iterator = a_iterator->next;
	}
	if (ps->r_u_f_a > (ps->a_size / 2))
	{
		ps->tmp_n_op_a = (ps->a_size - ps->r_u_f_a);
		ps->tmp_op_a = "rra";
	}
	else
	{
		ps->tmp_op_a = "ra";
		ps->tmp_n_op_a = ps->r_u_f_a;
	}
}

/*
	This function executes the rotations in stack_a and stack_b
	and execute pa, until stack_b is empty and all nodes are in
	stack_b, almost sorted, just needing to bring the smallest
	node to top.
*/
static void	execute_rotations(t_push_swap *ps)
{
	int	n_ops_a;
	int	n_ops_b;

	n_ops_a = ps->n_op_a;
	n_ops_b = ps->n_op_b;
	while (n_ops_a > 0 || n_ops_b > 0)
	{
		if (n_ops_a-- > 0)
		{
			if (ft_strncmp(ps->op_a, "ra", 2) == 0)
				ra(ps);
			else
				rra(ps);
		}
		if (n_ops_b-- > 0)
		{
			if (ft_strncmp(ps->op_b, "rb", 2) == 0)
				rb(ps);
			else
				rrb(ps);
		}
	}
	pa(ps);
}

static void	move_to_a(t_push_swap *ps)
{
	ps->b_node = NULL;
	while (ps->b_size)
	{
		ps->n_op_a = ps->a_size;
		ps->n_op_b = ps->b_size;
		ps->b_node = ps->b;
		while (ps->b_node != NULL)
		{
			calc_stack_b_rotations(ps);
			calc_stack_a_rotations(ps);
			if ((ps->tmp_n_op_a + ps->tmp_n_op_b) < (ps->n_op_a + ps->n_op_b))
			{
				ps->n_op_a = ps->tmp_n_op_a;
				ps->n_op_b = ps->tmp_n_op_b;
				ps->op_a = ps->tmp_op_a;
				ps->op_b = ps->tmp_op_b;
			}
			ps->b_node = ps->b_node->next;
		}
		execute_rotations(ps);
	}
}

/* fit sort because it rotate both stacks
   until achieve the exact position to
   fit nodes in correct position          */
void	fit_sort(t_push_swap *ps)
{
	move_to_b(ps);
	move_to_a(ps);
	bring_smaller_to_top(ps);
}
