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

#include <push_swap.h>

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

// static t_dll *what_is_the_smallest (t_dll *stack)
// {
// 	t_dll	*smallest;
// 	t_dll	*tmp;

// 	tmp = stack;
// 	smallest = stack;
// 	while (tmp->next_item != NULL)
// 	{
// 		tmp = tmp->next_item;
// 		if (tmp->value < smallest->value)
// 			smallest = tmp;
// 	}
// 	return (smallest);
// }
