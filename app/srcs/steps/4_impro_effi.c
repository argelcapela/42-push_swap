/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_impro_effi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/14 01:29:27 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	if_together(t_dll *ops, char *prev_op, char *cur_op)
{
	int	prev_op_size;
	int	cur_op_size;

	prev_op_size = ft_strlen(prev_op);
	cur_op_size = ft_strlen(cur_op);
	if (ft_strncmp(ops->previous->op_name, prev_op, prev_op_size) == 0
		&& ft_strncmp(ops->op_name, cur_op, cur_op_size) == 0)
		return (1);
	return (0);
}

static int	replace_with(t_push_swap *ps, t_dll **ops, char *op)
{
	t_dll	*after_last_replace;

	after_last_replace = (*ops)->next;
	(*ops)->previous->op_name = op;
	(*ops)->previous->next = after_last_replace;
	ft_free_ptr((void *) &(*ops));
	(*ops) = after_last_replace;
	ps->ops_size--;
	return (0);
}

void	improve_efficiency(t_push_swap *ps)
{
	t_dll	*tmp;

	tmp = ps->ops;
	while (tmp)
	{
		if (tmp == ps->ops)
		{
			tmp = tmp->next;
			continue ;
		}
		if (if_together(tmp, "ra", "rb"))
			replace_with(ps, &tmp, "rr");
		else if (if_together(tmp, "rra", "rrb"))
			replace_with(ps, &tmp, "rrr");
		else if (if_together(tmp, "sa", "sb"))
			replace_with(ps, &tmp, "ss");
		tmp = tmp->next;
	}
}
