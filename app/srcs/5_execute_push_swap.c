/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_execute_push_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/14 22:07:54 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort(t_push_swap *push_swap)
{
    if (push_swap->n == 2)
        sort_2_numbers(push_swap);
    else if (push_swap->n == 3)
        sort_3_numbers(push_swap);
    else if (push_swap->n > 3 && push_swap->n <= 5)
        sort_5_numbers(push_swap);
    else if (push_swap->n > 5 && push_swap->n <= 100)
        sort_100_numbers(push_swap);
    else if (push_swap->n > 100)
        sort_more_than_100_numbers(push_swap);
}

int execute_push_swap(t_push_swap *push_swap)
{
    sort(push_swap);
    // show stacks
    print_stack_horizontal(push_swap->stack_a, "STACK A");
    ft_printf("\n");
    print_stack_horizontal(push_swap->stack_b, "STACK B");
    return (0);
}
