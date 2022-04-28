/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/14 20:30:10 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* pa: Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */

void pa(t_push_swap *push_swap)
{
    t_dll   *tmp;

    tmp = push_swap->stack_a;
    if (push_swap->stack_a == NULL && push_swap->stack_b == NULL)
        return ;
    else if (push_swap->stack_b == NULL)
        return ;
    else if (tmp == NULL)
    {
        tmp = push_swap->stack_b;
        push_swap->stack_b = push_swap->stack_b->next_item;
        push_swap->stack_a = tmp;
        tmp->next_item = NULL;
    }
    else
    {
        tmp = push_swap->stack_b;
        push_swap->stack_b = push_swap->stack_b->next_item;
        tmp->next_item = push_swap->stack_a;
        push_swap->stack_a = tmp;
    }
    ft_printf("pa\n");
}
