/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/18 17:31:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void sort_2_numbers(t_push_swap *push_swap)
{
    t_dll   *n1;
    t_dll   *n2;

    if (stack_length(push_swap->stack_a) != 2)
        return ;
    n1 = push_swap->stack_a;
    n2 = push_swap->stack_a->next_item;
    if (n1->value > n2->value)
        sa(push_swap);
}

void sort_2_numbers_b(t_push_swap *push_swap)
{
    t_dll   *n1;
    t_dll   *n2;

    if (stack_length(push_swap->stack_b) < 2)
        return ;
    n1 = push_swap->stack_b;
    n2 = push_swap->stack_b->next_item;
    if (n1->value > n2->value)
        sb(push_swap);
}
