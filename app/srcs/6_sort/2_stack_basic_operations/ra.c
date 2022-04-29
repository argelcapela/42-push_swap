/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/29 11:19:11 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* ra: - The first element of stack a becomes the last one. */

void ra(t_push_swap *ps)
{
    t_dll   *first;
    t_dll   *second;
    t_dll   *last;

    if (ps->stack_a == NULL)
        return ;
    first = ps->stack_a;
    second = ps->stack_a->next;
    last  = ps->stack_a;
    while (last->next != NULL)
        last = last->next;
    last->next = first;
    first->next = NULL;
    ps->stack_a = second;
    ft_printf("ra\n");
}
