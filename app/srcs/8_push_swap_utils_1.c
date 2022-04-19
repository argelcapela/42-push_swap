/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_push_swap_utils_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/17 22:53:16 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		stack_length(t_dll *stack)
{
    int i;

    i = 1;
    if (stack == NULL)
        return (0);
    while (stack->next_item != NULL)
    {   
        stack = stack->next_item;
        i++;
    }
    return (i);
}

t_dll	*get_last_item(t_dll *stack)
{
    while (stack->next_item != NULL)
        stack = stack->next_item;
    return (stack);
}

void	reverse_stack(t_dll *stack, t_push_swap *push_swap)
{
	int	i;

	i = stack_length(stack);
	while (i-- >= 0)
		ra(push_swap);
}

