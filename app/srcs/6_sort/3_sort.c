/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_execute_push_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/18 17:55:25 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void sort(t_push_swap *push_swap)
{
    if (stack_already_is_sorted(push_swap) == 1)
        return ;
    if (push_swap->n == 2)
        sort_2_numbers(push_swap);
    else if (push_swap->n == 3)
        sort_3_numbers(push_swap);
    else if (push_swap->n > 3 && push_swap->n <= 5)
        sort_5_numbers(push_swap);
    else
        sort_more_than_5_numbers(push_swap);
}
