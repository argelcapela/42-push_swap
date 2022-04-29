/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_sort_more_than_5_numbers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/29 19:07:43 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void init_advanced_sorter(t_push_swap *ps)
{
	ps->stack_length = stack_length(ps->stack_a);
	ps->group_amount = 3;
	ps->group_size = ps->biggest_node_index / ps->group_amount;
}

static void rotator(t_push_swap *ps, int rotate_a, int rotate_b)
{
	while (rotate_a > 0)
	{
		rotate_a--;
		ra(ps);
	}
	while (rotate_a < 0)
	{
		rotate_a++;
		rra(ps);
	}
	while (rotate_b > 0)
	{
		rotate_b--;
		rb(ps);
	}
	while (rotate_b < 0)
	{
		rotate_b++;
		rrb(ps);
	}
}

static int	distance_to_top(t_dll *stack, int current_index, t_push_swap *ps)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == current_index)
			break;
		stack = stack->next;
		i++;
	}
	if (i > (ps->stack_length / 2))
		i -= ps->stack_length;
	return (i);
}

static t_dll *find_closest_in_group(t_dll *stack, t_push_swap *ps)
{
	t_dll	*closest;
	t_dll	*current;
	int		distance;
	int		current_distance_to_top;

	closest = NULL;
	current = stack;
	while (current)
	{
		if ((current->index <= ps->group_size * ps->current_group))
		{
			current_distance_to_top = distance_to_top(stack, current->index, ps);
			if (current_distance_to_top < distance)
			{
				distance = current_distance_to_top;
				closest = current;
				if (distance == 0)
					break;
			}
		}
		current = current->next;
	}
	return (closest);
}

void sort_more_than_5_numbers(t_push_swap *ps)
{
	int distance;

	init_advanced_sorter(ps);
	ps->current_group = 1;
	while (ps->stack_length >= 0 && ps->current_group <= (ps->group_amount + 1))
	{
		ps->temp = find_closest_in_group(ps->stack_a, ps);
		distance = distance_to_top(ps->stack_a, ps->temp->index, ps);
		if (ps->stack_a != NULL && distance == 0)
		{
			pb(ps);
			ps->stack_length--;
		}
		else
			rotator(ps, 1, 0);
	}
}
