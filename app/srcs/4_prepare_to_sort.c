/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_prepare_to_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/09 07:04:52 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******* JUST FOR TEST ********/

// static int  print_stack_vertical(t_dll *f_i_dll)
// {
//     t_dll   *tmp;

//     tmp = f_i_dll;
//     ft_printf("=== STACK A ===\n");
//     while (tmp->next_item != NULL)
//     {
//         ft_printf("%d\n", tmp->value);
//         tmp = tmp->next_item;
//     }
//     ft_printf("%d\n", tmp->value);
//     ft_printf("===============\n");
//     return (0);
// }


static int  print_stack_horizontal(t_dll *f_i_dll)
{
    t_dll   *tmp;

    tmp = f_i_dll;
    ft_printf("STACK A:\n");
    while (tmp->next_item != NULL)
    {
        ft_printf("%d ", tmp->value);
        tmp = tmp->next_item;
    }
    ft_printf("%d\n", tmp->value);
    return (0);
}

/*********************************************************/

static int fill_stack_a(t_push_swap *push_swap)
{
    int     i;
    t_dll   *tmp_dll;
    
    i = 1;
    push_swap->f_i_stack_a = (t_dll *) malloc(sizeof(t_dll));
    tmp_dll = push_swap->f_i_stack_a;
    tmp_dll->previous_item = NULL;
    tmp_dll->value = atoi(push_swap->argv[i]);
    while (++i < push_swap->argc)
    {
        tmp_dll->next_item = (t_dll *) malloc(sizeof(t_dll));
        tmp_dll->next_item->previous_item = tmp_dll;
        tmp_dll = tmp_dll->next_item;
        tmp_dll->value = atoi(push_swap->argv[i]);
        tmp_dll->next_item = NULL;
    }
    return (0);
}

int prepare_to_sort(t_push_swap *push_swap)
{
    fill_stack_a(push_swap);
    print_stack_horizontal(push_swap->f_i_stack_a);
    return (0);
}
