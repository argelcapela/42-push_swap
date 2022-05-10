/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_sort_more_than_5_numbers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/06 19:05:49 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	locate_high_num_pos(t_dll *head, int *high)
{
	int	i;
	int	high_pos;

	i = 0;
	*high = head->value;
	while (head)
	{
		if (head->value > *high)
		{
			*high = head->value;
			high_pos = i;
		}
		head = head->next;
		i++;
	}
	if (high_pos > i / 2)
		return (1);
	return (0);
}

static void	insert_back_to_a(t_push_swap *ps)
{
	int	high;
	int	rotation;

	while (ps->b != NULL)
	{
		rotation = locate_high_num_pos(ps->b, &high);
		while (ps->b->value != high)
		{
			if (rotation == 0)
				rb(ps);
			else
				rrb(ps);
		}
		pa(ps);
	}
}

void	sort_more_than_5_numbers(t_push_swap *ps)
{
	int	i;

	i = 0;
	while (ps->a != NULL)
	{
		if (ps->a->index <= ps->group_size)
		{
			pb(ps);
			ps->group_size++;
			if (ps->b->value > (last_item(ps->b))->value)
				rb(ps);
		}
		else
			ra(ps);
	}
	insert_back_to_a(ps);
}
