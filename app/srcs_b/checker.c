/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/14 02:49:06 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	print_ops(t_push_swap *ps)
{
	t_dll	*tmp;

	tmp = ps->ops;
	while (tmp)
	{
		ft_printf("%s", tmp->op_name);
		tmp = tmp->next;
	}
}


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
	if (receive_ops(ps) == 1)
	{
		clear(ps);
		exit(1);
	}
	execute_ops(ps);
	check_if_ops_sort(ps);
	// ft_dll_printv(ps->a, "resultado final:");
	// print_ops(ps);
	//ft_printf("op_size: %d\n", ps->ops_size);
	clear(ps);
	return (0);
}
