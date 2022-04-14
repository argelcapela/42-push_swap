/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_init_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/14 22:03:22 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int fill_stack_a(t_push_swap *push_swap)
{
    int     i;
    t_dll   *tmp_dll;
    
    if (push_swap->argc == 1)
    {
        push_swap->stack_a = NULL;
        return (0);
    }
    i = 1;
    push_swap->stack_a = (t_dll *) malloc(sizeof(t_dll));
    tmp_dll = push_swap->stack_a;
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

int init_push_swap(t_push_swap *push_swap)
{
    push_swap->n = push_swap->argc - 1;
    fill_stack_a(push_swap);
    return (0);
}
