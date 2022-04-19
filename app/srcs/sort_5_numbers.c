/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/18 17:34:11 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int is_already_sorted(t_push_swap *push_swap)
// {
// 	int	la;
// 	t_dll *tmp;

// 	la = get_last_item(push_swap->stack_a)->value;
// 	tmp = push_swap->stack_a;
// 	while (tmp->next_item != NULL)
// 	{
// 		if (tmp->value > la)
// 			return (0);
// 		tmp = push_swap->stack_a->next_item;
// 		la = get_last_item(tmp)->value;
// 	}
// 	return (1);
// }

void sort_5_numbers(t_push_swap *push_swap)
{
    int fa;
    int fb;
    int la;
	int	r;
    
	r = 0;
    if (stack_length(push_swap->stack_a) == 5)
	{
		pb(push_swap);
    	pb(push_swap);
	}
	else
		pb(push_swap);
    sort_3_numbers(push_swap);
    sort_2_numbers_b(push_swap);
    while (stack_length(push_swap->stack_b) > 0)
    {
        fa = push_swap->stack_a->value;
        fb = push_swap->stack_b->value;
        la = get_last_item(push_swap->stack_a)->value;
		if (fb < fa && fb < la)
			pa(push_swap);
		else if (fb > fa && fb > la)
		{
			pa(push_swap);
			ra(push_swap);
		}
		else if (fb > fa && fb < la)
		{
			r = 0;
			while (1)
			{
				ra(push_swap);
				r++;
				fa = push_swap->stack_a->value;
        		fb = push_swap->stack_b->value;
        		la = get_last_item(push_swap->stack_a)->value;
				if (fb < fa && fb > la)
				{
					pa(push_swap);
					break;
				}
			}
			while (r-- > 0)
				rra(push_swap);
		}
    }
}
