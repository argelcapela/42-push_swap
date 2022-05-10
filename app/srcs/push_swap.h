/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:03:14 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/04 18:49:36 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* libs */
# include            <stdlib.h>
# include            <unistd.h>
# include            "../libs/libft/srcs/libft.h"

/* c (constants) */
# define             INT_MAX 2147483647
# define             INT_MIN 2147483648
# define             FF 0xFFFFFFF

/*  s (structs) */
typedef struct s_push_swap
{
	struct s_dll		*a;
	struct s_dll		*b;
	int					argc;
	char				**argv;
	int					a_size;
	int					group_size;
}	t_push_swap;

// operations
void		ra(t_push_swap *ps);
void		rb(t_push_swap *ps);
void		rr(t_push_swap *ps);
void		rra(t_push_swap *ps);
void		rrb(t_push_swap *ps);
void		rrr(t_push_swap *ps);
void		sa(t_push_swap *ps);
void		sb(t_push_swap *ps);
void		ss(t_push_swap *ps);
void		pa(t_push_swap *ps);
void		pb(t_push_swap *ps);

// sort
void		two(t_push_swap *ps);
void		two2(t_push_swap *ps);
void		three(t_push_swap *ps);
void		five(t_push_swap *ps);
void		one_hundred(t_push_swap *ps);
void		five_hundred(t_push_swap *ps);

// steps
int			parse_error(int argc, char **argv);
t_push_swap	*init(int argc, char **argv);
void		sort(t_push_swap *ps);
void		clear(t_push_swap *ps);

// ps
int			push_swap(int argc, char **argv);

#endif
