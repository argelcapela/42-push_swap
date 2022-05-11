/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/10 22:49:25 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<push_swap.h>

static void	move_to_b_divide_two_groups (t_push_swap *ps)
{
	int	max;

	max = ps->a_size - 1;
	while (ps->a_size > 2)
	{
		if (ps->a->value == 0 || ps->a->value == max)
			ra(ps);
		else
			pb(ps);
		if (ps->b_size && ps->b->value > (max / 2))
			rb(ps);
		if (ft_dll_is_sorted(ps->a))
			break;
	}
}


// move_to_a
static void cost_stack_b(t_push_swap *ps, t_dll *b_node, t_costpa *costpa)
{
	int		top_distance_b;
	t_dll	*tmp;

	tmp = ps->b;
	top_distance_b = 0;
	while (tmp != b_node)
	{
		top_distance_b++;
		tmp = tmp->next;
		if (tmp == ft_dll_last(ps->b))
		{}
	}
}

static void cost_stack_b(t_push_swap *ps, t_dll *b_node, t_costpa *costpa)
{

}

static void	check_cost_pa(t_push_swap *ps, t_dll *b_node)
{
	t_cost_pa	costpa;

	cost_stack_b(ps, b_node, &costpa);
	cost_stack_a(ps, b_node, &costpa);
	if ((costpa->n_op_a + costpa->n_op_b)
		< (ps->cheaperst->n_op_a + ps->cheaperst->n_op_b))
	{
		ps->cheaperst->n_op_a = costpa.n_op_a;
		ps->cheaperst->n_op_b = costpa.n_op_b;
		ps->cheaperst->op_a = costpa->op_a;
		ps->cheaperst->op_b = costpa->op_b;
	}
}

static void get_lower_pa_cost(t_push_swap *ps)
{
	t_dll	*tmp;

	tmp = ps->b;
	while (tmp->next != NULL)
	{
		check_cost_pa(ps, tmp);
		tmp = tmp->next;
	}
	check_cost_pa(ps, tmp);
}

static void	move_to_a(t_push_swap *ps)
{
	while (ps->b_size)
	{
		ps->cheaperst->n_op_a = ps->a_size;
		ps->cheaperst->n_op_b = ps->b_size;
		get_lower_pa_cost(ps);
		execute_ops(ps);
	}
}

void	five_hundred(t_push_swap *ps)
{
	move_to_b_divide_two_groups(ps);
	move_to_a(ps);
	smaller_to_top(ps);
}
