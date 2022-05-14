/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/13 21:06:02 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int	main(int argc, char **argv)
{
	t_push_swap	*ps;

	if (parse_error(argc, argv) == 1)
	{
		ft_putstr_fd("Error", 2);
		exit(1);
	}
	else if (parse_error(argc, argv) == 2)
		exit(1);
	ps = init(argc, argv);
	if (receive_ops(ps) == 1)
	{
		clear(ps);
		exit(1);
	}
	execute_ops(ps);
	check_if_ops_sort(ps);
	clear(ps);
	return (0);
}
