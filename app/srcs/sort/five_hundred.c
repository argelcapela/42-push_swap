/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/13 23:13:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<push_swap.h>

static void	move_to_b_divide_two_groups (t_push_swap *ps)
{
	int	max;

	max = ps->a_size - 1;
	while (ps->a_size > 2)
	{
		if (ps->a->index == 0 || ps->a->index == max)
			ra(ps);
		else
			pb(ps);
		if ((ps->b_size >= 2) && ps->b->value > (max / 2))
			rb(ps);
		if (ft_dll_is_sorted(ps->a))
			break;
	}
}

void	count_how_many_rotations_stack_b_needs_until_b_node_arrive_top(t_push_swap *ps)
{
	t_dll	*b_iterator;

	ps->rotations_until_stack_b_top = 0;
	b_iterator = ps->b;
	while (b_iterator->value != ps->b_node->value)
	{
		ps->rotations_until_stack_b_top++;
		b_iterator = b_iterator->next;
	}
	if (ps->rotations_until_stack_b_top > (ps->b_size / 2))
	{
		ps->tmp_n_op_b = (ps->b_size - ps->rotations_until_stack_b_top);
		ps->tmp_op_b = ft_strdup("rrb");
	}
	else
	{
		ps->tmp_n_op_b = ps->rotations_until_stack_b_top;
		ps->tmp_op_b = ft_strdup("rb");
	}
}

void c_r_a_needs_when_execute_pa_b_first_node_fits_a_k_sorted(t_push_swap *ps)
{
	int	i;
	t_dll *a_iterator;

	ps->r_u_b_first_node_fits_a_without_messing_up_sorting = 0;
	a_iterator = ps->a;
	i = 0;
	while (i < ps->a_size)
	{
		if (a_iterator->index > ps->b_node->index && ft_dll_prev_index(ps->a, a_iterator) < ps->b_node->index)
			break;
		else
			i++;
		a_iterator = a_iterator->next;
	}
	ps->r_u_b_first_node_fits_a_without_messing_up_sorting = i;
	if (ps->r_u_b_first_node_fits_a_without_messing_up_sorting > (ps->a_size / 2))
	{
		ps->tmp_n_op_a = (ps->a_size - ps->r_u_b_first_node_fits_a_without_messing_up_sorting);
		ps->tmp_op_a = ft_strdup("rra");
	}
	else
	{
		ps->tmp_op_a = ft_strdup("ra");
		ps->tmp_n_op_a = ps->r_u_b_first_node_fits_a_without_messing_up_sorting;
	}
}

static void keep_lower_sum_of_n_op_a_and_b(t_push_swap *ps)
{
	if ((ps->tmp_n_op_a + ps->tmp_n_op_b) < (ps->n_op_a + ps->n_op_b))
	{
		ps->n_op_a = ps->tmp_n_op_a;
		ps->n_op_b = ps->tmp_n_op_b;
		ps->op_a = ft_strdup(ps->tmp_op_a);
		ps->op_b = ft_strdup(ps->tmp_op_b);
	}
}

static void execute_operations(t_push_swap *ps)
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

static void	move_to_a (t_push_swap *ps)
{
	ps->b_node = NULL;
	while (ps->b_size)
	{
		ps->n_op_a = ps->a_size;
		ps->n_op_b = ps->b_size;
		ps->b_node = ps->b;
		while (ps->b_node != NULL)
		{
			count_how_many_rotations_stack_b_needs_until_b_node_arrive_top(ps);
			c_r_a_needs_when_execute_pa_b_first_node_fits_a_k_sorted(ps);
			keep_lower_sum_of_n_op_a_and_b(ps);
			ps->b_node = ps->b_node->next;
		}
		execute_operations(ps);
	}
}

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

void	five_hundred(t_push_swap *ps)
{
	move_to_b_divide_two_groups(ps);
	move_to_a(ps);
	bring_smaller_to_top(ps);
}
