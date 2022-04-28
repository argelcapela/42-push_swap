/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_push_swap_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/18 17:36:00 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int stack_already_is_sorted(t_push_swap *push_swap)
{
    int     tmp;
    t_dll   *stack;

    stack = push_swap->stack_a;
    tmp = stack->value;
    while (stack->next_item != NULL)
    {
        stack = stack->next_item;
        if (stack->value < tmp)
            return (0);
        tmp = stack->value;
    }
    return (1);
}
