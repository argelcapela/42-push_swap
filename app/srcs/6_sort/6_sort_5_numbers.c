/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_sort_5_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/04 02:18:43 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_5_numbers_2(t_push_swap *ps, int *fa,
		int *fb, int *la)
{
	int	r;

	r = 0;
	while (1)
	{
		ra(ps);
		r++;
		*fa = ps->a->value;
		*fb = ps->b->value;
		*la = last_item(ps->a)->value;
		if (*fb < *fa && *fb > *la)
		{
			pa(ps);
			break ;
		}
	}
	while (r-- > 0)
		rra(ps);
}

static void	double_pb(t_push_swap *ps)
{
	pb(ps);
	pb(ps);
}

void	sort_5_numbers(t_push_swap *ps)
{
	int	fa;
	int	fb;
	int	la;

	if (stack_length(ps->a) == 5)
		double_pb(ps);
	else
		pb(ps);
	sort_3_numbers(ps);
	sort_2_numbers_b(ps);
	while (stack_length(ps->b) > 0)
	{
		fa = ps->a->value;
		fb = ps->b->value;
		la = last_item(ps->a)->value;
		if (fb < fa && fb < la)
			pa(ps);
		else if (fb > fa && fb > la)
		{
			pa(ps);
			ra(ps);
		}
		else if (fb > fa && fb < la)
			sort_5_numbers_2(ps, &fa, &fb, &la);
	}
}
