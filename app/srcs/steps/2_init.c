/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:45:26 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/14 15:41:03 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

static t_dll	*get_next_smallest(t_dll **stack)
{
	int		has_index;
	t_dll	*smallest;
	t_dll	*head;

	has_index = 0;
	smallest = NULL;
	head = *stack;
	while (head)
	{
		if ((head->index == -1) && (has_index == 0
				|| head->value < smallest->value))
		{
			smallest = head;
			has_index = 1;
		}
		head = head->next;
	}
	return (smallest);
}

static void	sort_indexes(t_dll **stack)
{
	t_dll	*head;
	int		i;

	i = 0;
	head = get_next_smallest(stack);
	while (head)
	{
		head->index = i++;
		head = get_next_smallest(stack);
	}
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
	ps->b = NULL;
	ps->op_a = "";
	ps->op_b = "";
	ps->tmp_op_a = "";
	ps->tmp_op_b = "";
	fill_a(ps);
	ps->ops = NULL;
	sort_indexes(&(ps->a));
	return (ps);
}
