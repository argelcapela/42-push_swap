/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/14 20:28:02 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pb: Take the first element at the top of a and put it at the top of a.
Do nothing if a is empty. */

void pb(t_push_swap *push_swap)
{
    t_dll   *tmp;

    tmp = push_swap->stack_b;
    if (push_swap->stack_a == NULL && push_swap->stack_b == NULL)
        return ;
    else if (push_swap->stack_a == NULL)
        return ;
    else if (tmp == NULL)
    {
        tmp = push_swap->stack_a;
        push_swap->stack_a = push_swap->stack_a->next_item;
        push_swap->stack_b = tmp;
        tmp->next_item = NULL;
    }
    else
    {
        tmp = push_swap->stack_a;
        push_swap->stack_a = push_swap->stack_a->next_item;
        tmp->next_item = push_swap->stack_b;
        push_swap->stack_b = tmp;
    }
    ft_printf("pb\n");
}