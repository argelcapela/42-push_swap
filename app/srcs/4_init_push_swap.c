/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_init_ps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/29 11:17:29 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int fill_stack_a(t_push_swap *ps)
{
	int     i;
	t_dll   *tmp_dll;

	if (ps->argc == 1)
	{
		ps->stack_a = NULL;
		return (0);
	}
	i = 1;
	ps->stack_a = (t_dll *) malloc(sizeof(t_dll));
	tmp_dll = ps->stack_a;
	tmp_dll->previous = NULL;
	tmp_dll->value = atoi(ps->argv[i]);
	tmp_dll->index = -1;
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


/* Loop all stack_a searching the node with the smallest value that
don't have an index yet. This node is returned and receive an index. */
static t_dll *get_next_smallest(t_dll **stack)
{
	int     has_index;
	t_dll   *smallest;
	t_dll   *head;

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

/* fill stack_a with sorted indexes starting from smallest
ending on the biggest. Function end when all the nodes
receive an index different of -1. */
static void sort_indexes(t_dll **stack, t_push_swap *ps)
{
	t_dll   *head;
	int     i;

	i = 0;
	head = get_next_smallest(stack);
	while (head)
	{
		head->index = i++;
		head = get_next_smallest(stack);
	}
	ps->biggest_node_index = i;
}




int init_push_swap(t_push_swap *ps)
{
	ps->stack_length = ps->argc - 1;
	fill_stack_a(ps);
	sort_indexes(&(ps->stack_a), ps);
    //print_stack_vertical(ps->stack_a);
	return (0);
}
