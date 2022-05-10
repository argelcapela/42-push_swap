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

// Libs
# include            <stdlib.h>

# include            <unistd.h>

# include            "../libs/libft/libft.h"

// Constants
# define             INT_MAX 2147483647

# define             INT_MIN 2147483648

# define             FF 0xFFFFFFF

// Structs
typedef struct s_dll
{
	struct s_dll		*previous;
	struct s_dll		*next;
	int					keep;
	int					index;
	int					value;
}	t_dll;

typedef struct s_push_swap
{
	struct s_dll		*a;
	struct s_dll		*b;
	int					argc;
	char				**argv;
	int					stack_length;
	int					group_size;
}	t_push_swap;

// App
t_push_swap	*init_push_swap(int argc, char **argv);

int			push_swap(int argc, char **argv);

int			identify_errors(int argc, char **argv);

int			execute_push_swap(t_push_swap *ps);

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

// Sort
void		sort(t_push_swap *ps);

void		sort_2_numbers(t_push_swap *ps);

void		sort_2_numbers_b(t_push_swap *ps);

void		sort_3_numbers(t_push_swap *ps);

void		sort_5_numbers(t_push_swap *ps);

void		sort_more_than_5_numbers(t_push_swap *ps);

// Utils
int			stack_length(t_dll *stack);

int			is_sorted(t_dll *stack);

int			print_stack_vertical(t_dll *f_i_dll);

int			print_stack_horizontal(t_dll *stack, char *title);

t_dll		*last_item(t_dll *stack);

// Free
void		free_stack(t_dll *stack);

void		clear_app(t_push_swap *ps);

#endif
