/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/14 21:34:35 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rb: - The first element of stack b becomes the last one. */

void rb(t_push_swap *push_swap)
{
    t_dll   *first;
    t_dll   *second;
    t_dll   *last;
    
    if (push_swap->stack_b == NULL)
        return ;
    first = push_swap->stack_b;
    second = push_swap->stack_b->next_item;
    last  = push_swap->stack_b;
    while (last->next_item != NULL)
        last = last->next_item;
    last->next_item = first;
    first->next_item = NULL;
    push_swap->stack_b = second;
    ft_printf("rb\n");
}