/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_sort_2_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/03 16:48:33 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void sort_2_numbers(t_push_swap *ps)
{
    t_dll   *n1;
    t_dll   *n2;

    if (stack_length(ps->a) != 2)
        return ;
    n1 = ps->a;
    n2 = ps->a->next;
    if (n1->value > n2->value)
        sa(ps);
}

void sort_2_numbers_b(t_push_swap *ps)
{
    t_dll   *n1;
    t_dll   *n2;

    if (stack_length(ps->b) < 2)
        return ;
    n1 = ps->b;
    n2 = ps->b->next;
    if (n1->value > n2->value)
        sb(ps);
}
