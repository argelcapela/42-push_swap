/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/29 11:19:28 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* sb:
         - swap the first 2 elements at the top of stack b.
         - [0] = 1 and [1] = 33 when we swap we have: [0] = 33 and [1] = 1 */

void sb(t_push_swap *ps)
{
    int tmp;

    if (stack_length(ps->stack_b) <= 1)
        return ;
    tmp = ps->stack_b->value;
    ps->stack_b->value = ps->stack_b->next->value;
    ps->stack_b->next->value = tmp;
    ft_printf("sb\n");
}
