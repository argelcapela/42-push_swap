/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hacksaw_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/14 01:42:19 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<push_swap.h>

static void	back_to_a(t_push_swap *ps);
static int	get_biggest_value_in_b(t_dll *head, int *biggest);

void	hacksaw_sort(t_push_swap *ps)
{
	int	i;

	i = 0;
	while (ps->a != NULL)
	{
		if (ps->a->index <= ps->group_size)
		{
			pb(ps);
			ps->group_size++;
			if (ps->b->value > (ft_dll_last(ps->b))->value)
				rb(ps);
		}
		else
			ra(ps);
	}
	back_to_a(ps);
}

static int	get_biggest_value_in_b(t_dll *head, int *biggest)
{
	int	i;
	int	biggest_pos;

	i = 0;
	*biggest = head->value;
	while (head)
	{
		if (head->value > *biggest)
		{
			*biggest = head->value;
			biggest_pos = i;
		}
		head = head->next;
		i++;
	}
	if (biggest_pos > i / 2)
		return (1);
	return (0);
}

static void	back_to_a(t_push_swap *ps)
{
	int	b_biggest_value;
	int	b_rotation;

	while (ps->b != NULL)
	{
		b_rotation = get_biggest_value_in_b(ps->b, &b_biggest_value);
		while (ps->b->value != b_biggest_value)
		{
			if (b_rotation == 0)
				rb(ps);
			else
				rrb(ps);
		}
		pa(ps);
	}
}
