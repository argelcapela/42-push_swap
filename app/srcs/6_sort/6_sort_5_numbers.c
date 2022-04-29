/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_sort_5_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/29 13:52:30 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void sort_5_numbers(t_push_swap *ps)
{
    int fa;
    int fb;
    int la;
	int	r;

	r = 0;
    if (stack_length(ps->stack_a) == 5)
	{
		pb(ps);
    	pb(ps);
	}
	else
		pb(ps);
    sort_3_numbers(ps);
    sort_2_numbers_b(ps);
    while (stack_length(ps->stack_b) > 0)
    {
        fa = ps->stack_a->value;
        fb = ps->stack_b->value;
        la = last_item(ps->stack_a)->value;
		if (fb < fa && fb < la)
			pa(ps);
		else if (fb > fa && fb > la)
		{
			pa(ps);
			ra(ps);
		}
		else if (fb > fa && fb < la)
		{
			r = 0;
			while (1)
			{
				ra(ps);
				r++;
				fa = ps->stack_a->value;
        		fb = ps->stack_b->value;
        		la = last_item(ps->stack_a)->value;
				if (fb < fa && fb > la)
				{
					pa(ps);
					break;
				}
			}
			while (r-- > 0)
				rra(ps);
		}
    }
}
