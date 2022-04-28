/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/14 21:34:30 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* ra: - The first element of stack a becomes the last one. */

void ra(t_push_swap *push_swap)
{
    t_dll   *first;
    t_dll   *second;
    t_dll   *last;

    if (push_swap->stack_a == NULL)
        return ;
    first = push_swap->stack_a;
    second = push_swap->stack_a->next_item;
    last  = push_swap->stack_a;
    while (last->next_item != NULL)
        last = last->next_item;
    last->next_item = first;
    first->next_item = NULL;
    push_swap->stack_a = second;
    ft_printf("ra\n");
}
