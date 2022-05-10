/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/10 04:27:19 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_push_swap	*ps;

	if (identify_errors(argc, argv) == 1)
	{
		ft_putstr_fd("Error", 2);
		exit(1);
	}
	else if (identify_errors(argc, argv) == 2)
		exit(1);
	ps = init_push_swap(argc, argv);
	execute_push_swap(ps);
	clear_app(ps);
	return (0);
}
