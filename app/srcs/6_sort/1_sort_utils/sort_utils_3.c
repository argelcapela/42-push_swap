/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_push_swap_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/18 17:36:00 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*

	JUST FOR TEST BEFORE - EVALUATION

*/

int		print_stack_vertical(t_dll *f_i_dll)
{
    t_dll   *tmp;

    tmp = f_i_dll;
    ft_printf("=== STACK A ===\n");
    while (tmp->next_item != NULL)
    {
        ft_printf("%d\n", tmp->value);
        tmp = tmp->next_item;
    }
    ft_printf("%d\n", tmp->value);
    ft_printf("===============\n");
    return (0);
}

int		print_stack_horizontal(t_dll *stack, char *title)
{
    t_dll   *tmp;

    tmp = stack;
    ft_printf("%s:\n", title);
    if (stack == NULL)
        return (0);
    while (tmp->next_item != NULL)
    {
        ft_printf("%d ", tmp->value);
        tmp = tmp->next_item;
    }
    ft_printf("%d\n", tmp->value);
    return (0);
}