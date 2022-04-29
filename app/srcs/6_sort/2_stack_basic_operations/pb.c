/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/29 11:19:09 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* pb: Take the first element at the top of a and put it at the top of a.
Do nothing if a is empty. */

void pb(t_push_swap *ps)
{
    t_dll   *tmp;

    tmp = ps->stack_b;
    if (ps->stack_a == NULL && ps->stack_b == NULL)
        return ;
    else if (ps->stack_a == NULL)
        return ;
    else if (tmp == NULL)
    {
        tmp = ps->stack_a;
        ps->stack_a = ps->stack_a->next;
        ps->stack_b = tmp;
        tmp->next = NULL;
    }
    else
    {
        tmp = ps->stack_a;
        ps->stack_a = ps->stack_a->next;
        tmp->next = ps->stack_b;
        ps->stack_b = tmp;
    }
    ft_printf("pb\n");
}
