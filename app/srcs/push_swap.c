/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/14 17:15:19 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_push_swap	*ps;

	if (parse_error(argc, argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else if (parse_error(argc, argv) == 2)
		exit(1);
	ps = init(argc, argv);
	sort(ps);
	improve_efficiency(ps);
	print_ops(ps);
	clear(ps);
	return (0);
}
