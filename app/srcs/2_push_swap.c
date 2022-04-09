/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/09 06:57:15 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char **argv)
{
    t_push_swap *push_swap;
    
    if (identify_erros(argc, argv) != 0)
        exit(1);
    push_swap = (t_push_swap *) malloc(sizeof(t_push_swap));
    push_swap->argc = argc;
    push_swap->argv = argv;
    prepare_to_sort(push_swap);
    return (0);
}
