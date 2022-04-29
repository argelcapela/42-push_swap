/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_sort_2_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/29 11:21:03 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void sort_2_numbers(t_push_swap *ps)
{
    t_dll   *n1;
    t_dll   *n2;

    if (stack_length(ps->stack_a) != 2)
        return ;
    n1 = ps->stack_a;
    n2 = ps->stack_a->next;
    if (n1->value > n2->value)
        sa(ps);
}

void sort_2_numbers_b(t_push_swap *ps)
{
    t_dll   *n1;
    t_dll   *n2;

    if (stack_length(ps->stack_b) < 2)
        return ;
    n1 = ps->stack_b;
    n2 = ps->stack_b->next;
    if (n1->value > n2->value)
        sb(ps);
}
