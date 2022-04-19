/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/16 03:06:49 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3_numbers(t_push_swap *push_swap)
{
    int   n1;
    int   n2;
    int   n3;

    n1 = push_swap->stack_a->value;
    n2 = push_swap->stack_a->next_item->value;
    n3 = push_swap->stack_a->next_item->next_item->value;
    if (n1 > n2 && n2 < n3 && n1 < n3)
        sa(push_swap);
    else if (n1 > n2 && n2 > n3 && n1 > n3) 
    {
        sa(push_swap);
        rra(push_swap);
    }
    else if (n1 > n2 && n2 < n3 && n1 > n3) 
        ra(push_swap);
    else if (n1 < n2 && n2 > n3 && n1 < n3) 
    {
        sa(push_swap);
        ra(push_swap);
    }
    else if (n1 < n2 && n2 > n3 && n1 > n3) 
        rra(push_swap);
}
