/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/29 11:19:04 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* pa: Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */

void pa(t_push_swap *ps)
{
    t_dll   *tmp;

    tmp = ps->stack_a;
    if (ps->stack_a == NULL && ps->stack_b == NULL)
        return ;
    else if (ps->stack_b == NULL)
        return ;
    else if (tmp == NULL)
    {
        tmp = ps->stack_b;
        ps->stack_b = ps->stack_b->next;
        ps->stack_a = tmp;
        tmp->next = NULL;
    }
    else
    {
        tmp = ps->stack_b;
        ps->stack_b = ps->stack_b->next;
        tmp->next = ps->stack_a;
        ps->stack_a = tmp;
    }
    ft_printf("pa\n");
}
