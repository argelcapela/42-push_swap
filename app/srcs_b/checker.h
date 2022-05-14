/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:03:14 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/14 22:42:56 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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
	t_dll				*a;
	t_dll				*b;
	t_dll				*ops;
	int					ops_size;
	int					argc;
	char				**argv;
	int					group_size;
	int					a_size;
	int					b_size;
	char				*op_a;
	char				*op_b;
	int					n_op_a;
	int					n_op_b;
	char				*tmp_op_a;
	char				*tmp_op_b;
	int					tmp_n_op_a;
	int					tmp_n_op_b;
	int					tmp_lower_n_op_a_b;
	int					distance_until_top_a;
	int					distance_until_top_b;
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

// steps
int			parse_error(int argc, char **argv);
t_push_swap	*init(int argc, char **argv);
int			receive_ops(t_push_swap *ps);
void		execute_ops(t_push_swap *ps, int *error);
void		check_if_ops_sort(t_push_swap *ps);
void		clear(t_push_swap *ps);

// utils
void		ft_dll_op_add_back(t_push_swap *ps, char *op_name);

// ps
int			push_swap(int argc, char **argv);

#endif
