/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/17 23:17:05 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_dll *what_is_the_smallest (t_dll *stack)
{
	t_dll	*smallest;
	t_dll	*tmp;

	tmp = stack;
	smallest = stack;
	while (tmp->next_item != NULL)
	{
		tmp = tmp->next_item;
		if (tmp->value < smallest->value)
			smallest = tmp;
	}
	return (smallest);
}

static void put_smallest_on_top (t_dll *stack, t_push_swap *push_swap)
{
	t_dll	*smallest;
	//t_dll	*first;
	int		i;
	t_dll	*tmp;

	i = 0;
	tmp = stack;
	smallest = what_is_the_smallest(stack);
	while (tmp->next_item != NULL)
	{
		tmp = tmp->next_item;
		if (tmp->value == smallest->value)
		{			
			if (i <= stack_length(stack))
				while (i-- >= 0)
					ra(push_swap);
			else
				while ((stack_length(stack) - i) - 1 >= 0)
					rra(push_swap);	
			return ;		
		}
		i++;
	}
}


void sort_100_numbers(t_push_swap *push_swap)
{
	int	i;
	int	z;

	z = 0;
	i = stack_length(push_swap->stack_a);
	// sort in stack b -> find smallet and push to b
	while (z < i)
	{
		put_smallest_on_top(push_swap->stack_a, push_swap);
		pb(push_swap);
		z++;
	}
	z = 0;
	// put again to a
	while (z < i)
	{
		pa(push_swap);
		 z++;
	}
}