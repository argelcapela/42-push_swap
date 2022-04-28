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

int execute_push_swap(t_push_swap *push_swap)
{
	//  print_stack_horizontal(push_swap->stack_a, "STACK A");
    //  ft_printf("\n");
    //  print_stack_horizontal(push_swap->stack_b, "STACK B");
    sort(push_swap);
    // show stacks
    // print_stack_horizontal(push_swap->stack_a, "STACK A");
    // ft_printf("\n");
    // print_stack_horizontal(push_swap->stack_b, "STACK B");
    return (0);
}
