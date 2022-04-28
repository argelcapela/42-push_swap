/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/14 21:53:34 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* sa:
         - swap the first 2 elements at the top of stack a.
         - [0] = 1 and [1] = 33 when we swap we have: [0] = 33 and [1] = 1 */

void sa(t_push_swap *push_swap)
{
    int tmp;

    if (stack_length(push_swap->stack_a) <= 1)
        return ;
    tmp = push_swap->stack_a->value;
    push_swap->stack_a->value = push_swap->stack_a->next_item->value;
    push_swap->stack_a->next_item->value = tmp;
    ft_printf("sa\n");
}
