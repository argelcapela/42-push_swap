/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/29 13:51:40 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		stack_length(t_dll *stack)
{
    int i;

    i = 1;
    if (stack == NULL)
        return (0);
    while (stack->next != NULL)
    {
        stack = stack->next;
        i++;
    }
    return (i);
}

t_dll	*last_item(t_dll *stack)
{
    while (stack->next != NULL)
        stack = stack->next;
    return (stack);
}

int is_sorted(t_dll *stack)
{
    int     tmp;

    tmp = stack->value;
    while (stack->next != NULL)
    {
        stack = stack->next;
        if (stack->value < tmp)
            return (0);
        tmp = stack->value;
    }
    return (1);
}
