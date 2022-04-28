/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/14 21:34:09 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* rrb: - The last element of stack b becomes the first one. */

void rrb(t_push_swap *push_swap)
{
    t_dll   *first;
    t_dll   *before_last;
    t_dll   *last;

    if (push_swap->stack_b == NULL)
        return ;
    first = push_swap->stack_b;
    last  = push_swap->stack_b;
    while (last->next_item != NULL)
    {
        before_last = last;
        last = last->next_item;
    }
    last->next_item = first;
    before_last->next_item = NULL;
    push_swap->stack_b = last;
    ft_printf("rrb\n");
}
