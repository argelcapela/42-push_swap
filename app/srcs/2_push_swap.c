/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/29 11:17:06 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


int	push_swap(int argc, char **argv)
{
    t_push_swap *ps;

    if (identify_erros(argc, argv) == 1)
	{
		ft_putstr_fd("Error", 2);
        exit(1);
	}
	else if (identify_erros(argc, argv) == 2)
		exit(1);
    ps = (t_push_swap *) malloc(sizeof(t_push_swap));
    ps->argc = argc;
    ps->argv = argv;
    init_push_swap(ps);
    return (execute_push_swap(ps));
}
