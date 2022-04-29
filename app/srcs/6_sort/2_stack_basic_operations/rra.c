/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/29 11:19:19 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* rra: - The last element of stack a becomes the first one. */

void rra(t_push_swap *ps)
{
    t_dll   *first;
    t_dll   *before_last;
    t_dll   *last;

    if (ps->stack_a == NULL)
        return ;
    first = ps->stack_a;
    last  = ps->stack_a;
    while (last->next != NULL)
    {
        before_last = last;
        last = last->next;
    }
    last->next = first;
    before_last->next = NULL;
    ps->stack_a = last;
    ft_printf("rra\n");
}
