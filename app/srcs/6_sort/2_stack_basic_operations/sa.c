/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/29 11:19:25 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* sa:
         - swap the first 2 elements at the top of stack a.
         - [0] = 1 and [1] = 33 when we swap we have: [0] = 33 and [1] = 1 */

void sa(t_push_swap *ps)
{
    int tmp;

    if (stack_length(ps->stack_a) <= 1)
        return ;
    tmp = ps->stack_a->value;
    ps->stack_a->value = ps->stack_a->next->value;
    ps->stack_a->next->value = tmp;
    ft_printf("sa\n");
}
