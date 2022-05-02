/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_sort_more_than_5_numbers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/02 16:57:52 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static void rotate(t_push_swap *ps, int rotate_a, int rotate_b)
{
	while (rotate_a > 0)
	{
		rotate_a--;
		ra(ps);
	}
	while (rotate_a < 0)
	{
		rotate_a++;
		rra(ps);
	}
	while (rotate_b > 0)
	{
		rotate_b--;
		rb(ps);
	}
	while (rotate_b < 0)
	{
		rotate_b++;
		rrb(ps);
	}
}

int	distance_to_top(t_dll *a, int tag)
{
	int	i;
	int	size;

	i = 0;
	size = stack_length(a);
	while (a)
	{
		if (a->index == tag)
			break;
		a = a->next;
		i++;
	}
	if (i > (size / 2))
		i -= size;
	return (i);
}

t_dll *closest_in_group(t_dll *list, int cur_group, int group_sz)
{
	t_dll	*closest;
	t_dll	*cur;
	int		distance;
	int		cur_dist;

	distance = FF;
	closest = NULL;
	cur = list;
	while (cur)
	{
		if (cur->index <= group_sz * cur_group && !cur->keep)
		{
			cur_dist = distance_to_top(list, cur->index);
			if (ft_abs(cur_dist) < ft_abs(distance))
			{
				distance = cur_dist;
				closest = cur;
				if (distance == 0)
					break;
			}
		}
		cur = cur->next;
	}
	return (closest);
}



int	loop_list(t_dll *list, t_dll *start, int set)
{
	t_dll	*loop;
	int		max_tag;
	int		count;

	max_tag = -1;
	count = 0;
	loop = start;
	while (loop)
	{
		if (set)
			loop->keep = 0;
		if (loop->index > max_tag)
		{
			max_tag = loop->index;
			count++;
			if (set)
				loop->keep = 1;
		}
		loop = loop->next;
		if (loop == NULL)
			loop = list;
		if (loop == start)
			break ;
	}
	return (count);
}

int	find_biggest_loop(t_dll *start, int set)
{
	t_dll	*t;
	int		max;
	int		count;
	t_dll	*max_keep;

	max = 0;
	t = start;
	while (t)
	{
		count = loop_list(start, t, 0);
		if (count > max)
		{
			max = count;
			max_keep = t;
		}
		t = t->next;
	}
	if (set)
		loop_list(start, max_keep, 1);
	return (max);
}

int	can_swap(t_dll *list)
{
	t_dll	fake;
	t_dll	fake2;
	int		count;
	int		count2;

	fake.next = &fake2;
	fake.index = list->next->index;
	fake2.next = list->next->next;
	fake2.index = list->index;
	count = find_biggest_loop(list, 0);
	count2 = find_biggest_loop(&fake, 0);
	if (count2 > count)
		return (1);
	return (0);
}

int insert_distance(t_dll *list, int t, int size)
{
	t_dll	*p;
	t_dll	*c;
	int		c_max[2];
	int		i;

	i = 0;
	p = last_item(list);
	c = list;
	c_max[1] = FF;
	while (c)
	{
		if ((p->index > c->index && (t < c->index || t > p->index)) || (t > p->index && t < c->index))
		{
			c_max[0] = i;
			if (c_max[0] > size / 2)
				c_max[0] -= size;
			if (ft_abs(c_max[0]) < c_max[1])
				c_max[1] = c_max[0];
		}
		p = c;
		c = c->next;
		i++;
	}
	return (c_max[1]);
}

int distance_to_tag(int tag, int size)
{
	if (tag >= size / 2)
		tag  -= size;
	return (tag);
}

void	calculate_b_rotation(t_push_swap *ps, int max_dist, int *rot_a, int *rot_b)
{
	int	dist_total;
	int	insert;
	int	distance_b;
	int	i;

	i = 0;
	ps->temp = ps->stack_b;
	while (ps->temp)
	{
		distance_b = distance_to_tag(i++, ps->biggest_node_index - ps->stack_length);
		insert = insert_distance(ps->stack_a, ps->temp->index, ps->stack_length);
		dist_total = ft_abs(insert) + ft_abs(distance_b);
		if (insert > 0 && distance_b > 0)
			dist_total -= ft_min(distance_b, insert);
		if (insert < 0 && distance_b < 0)
			dist_total += ft_max(distance_b, insert);
		if (dist_total < max_dist)
		{
			max_dist = dist_total;
			*rot_a = insert;
			*rot_b = distance_b;
		}
		ps->temp = ps->temp->next;
	}
}

void	populate_b(t_push_swap *ps)
{
	int	rot_a;
	int	rot_b;

	while (ps->stack_b)
	{
		calculate_b_rotation(ps, FF, &rot_a, &rot_b);
		rotate(ps, rot_a, rot_b);
		pa(ps);
		(ps->stack_length)++;
	}
	rotate(ps, distance_to_top(ps->stack_a, 0), 0);
}

static void init_advanced_sorter(t_push_swap *ps)
{
	ps->big = find_biggest_loop(ps->stack_a, 1);
	ps->stack_length = stack_length(ps->stack_a);
	ps->group_amount = ft_max(1, (int)(ps->biggest_node_index / 150.0));
	ps->group_size = ps->biggest_node_index / ps->group_amount;
}

void sort_more_than_5_numbers(t_push_swap *ps)
{
	int distance;

	init_advanced_sorter(ps);
	ps->current_group = 1;
	while (ps->stack_length >= ps->big && ps->current_group <= (ps->group_amount + 1))
	{
		//ft_printf("%d %d %d %d",ps->stack_length, ps->big, ps->current_group, ps->group_amount);
		 //exit(0);
		ps->temp = closest_in_group(ps->stack_a, ps->current_group, ps->group_size);
		if (ps->temp == NULL && ++ps->current_group)
			continue;
		distance = distance_to_top(ps->stack_a, ps->temp->index);
		if (ps->stack_a && can_swap(ps->stack_a))
		{
			sa(ps);
			ps->big = find_biggest_loop(ps->stack_a, 1);
		}
		else if (ps->stack_a && !ps->stack_a->keep && distance == 0)
		{
			pb(ps);
			(ps->stack_length)--;
		}
		else if (ps->group_amount == 1)
			rr(ps);
		else
			rotate(ps, ft_min(1, ft_max(-1, distance)), 0);

	ft_printf("%d %d\n", ps->stack_a->value, can_swap(ps->stack_a));
		
	}
	populate_b(ps);
}
