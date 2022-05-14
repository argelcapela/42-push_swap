/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:45:26 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/14 03:10:47 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int	fill_a(t_push_swap *ps)
{
	int		i;
	t_dll	*tmp_dll;

	if (ps->argc == 1)
	{
		ps->a = NULL;
		return (0);
	}
	i = 1;
	ps->a = (t_dll *) malloc(sizeof(t_dll));
	tmp_dll = ps->a;
	tmp_dll->previous = NULL;
	tmp_dll->value = atoi(ps->argv[i]);
	tmp_dll->index = -1;
	tmp_dll->next = NULL;
	while (++i < ps->argc)
	{
		tmp_dll->next = (t_dll *) malloc(sizeof(t_dll));
		tmp_dll->next->previous = tmp_dll;
		tmp_dll = tmp_dll->next;
		tmp_dll->value = atoi(ps->argv[i]);
		tmp_dll->next = NULL;
		tmp_dll->index = -1;
	}
	return (0);
}

t_push_swap	*init(int argc, char **argv)
{
	t_push_swap	*ps;

	ps = (t_push_swap *) malloc(sizeof(t_push_swap));
	ps->argc = argc;
	ps->argv = argv;
	ps->a_size = ps->argc - 1;
	ps->b_size = 0;
	ps->ops_size = 0;
	fill_a(ps);
	ps->b = NULL;
	ps->ops = NULL;
	return (ps);
}
