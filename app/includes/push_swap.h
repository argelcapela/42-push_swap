/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:03:14 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/03 17:55:03 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*#################################################
#  						  						           #
#   				libs	  					              #
#						  						              #
#################################################*/

// malloc, free
# include <stdlib.h>

// read, write
# include <unistd.h>

// libft, get_next_line, ft_printf, etc..
# include "../libs/libft/libft.h"

/*#################################################
#  						  						           #
#   				macros	  					           #
#						  						              #
#################################################*/

# define INT_MAX 2147483647

# define INT_MIN 2147483648

# define FF 0xFFFFFFF

/*#################################################
#  						  						           #
#   				structs	  				              #
#						  						              #
#################################################*/

// linked list
typedef struct s_dll
{
	struct s_dll	*previous;
	struct s_dll	*next;
   int            keep;
   int            index;
	int				value;
}	t_dll;

typedef struct s_push_swap
{
   int            argc;
   char**         argv;
	struct s_dll   *a;
   struct s_dll   *b;
   int            group_size;
   int            current_group;
   int            stack_length;
}	t_push_swap;

/*#################################################
#  						  						           #
#   			     2_push_swap.c   		           #
#						  						              #
#################################################*/

int		push_swap(int argc, char **argv);

/*#################################################
#  						  						           #
#   		     3_identify_errors.c	              #
#						  						              #
#################################################*/

int	   identify_erros(int argc, char **argv);

/*#################################################
#  						  						           #
#   		     4_init_push_swap.c	   	           #
#						  						              #
#################################################*/

int      init_push_swap(t_push_swap *ps);

/*#################################################
#  						  						           #
#   		    5_execute_push_swap.c  	           #
#						  						              #
#################################################*/

int      execute_push_swap(t_push_swap *ps);

/*#################################################
#  						  						           #
#   			  6_basic_movements			           #
#						  						              #
#################################################*/

void     ra(t_push_swap *ps);

void     rb(t_push_swap *ps);

void     rr(t_push_swap *ps);

void     rra(t_push_swap *ps);

void     rrb(t_push_swap *ps);

void     rrr(t_push_swap *ps);

void     sa(t_push_swap *ps);

void     sb(t_push_swap *ps);

void     ss(t_push_swap *ps);

void     pa(t_push_swap *ps);

void     pb(t_push_swap *ps);

/*#################################################
#  						  						           #
#      7_sort_with_least_amount_of_movements      #
#						  						              #
#################################################*/

void     sort(t_push_swap *ps);

void     sort_2_numbers(t_push_swap *ps);

void     sort_2_numbers_b(t_push_swap *ps);

void     sort_3_numbers(t_push_swap *ps);

void     sort_5_numbers(t_push_swap *ps);

void     sort_more_than_5_numbers(t_push_swap *ps);

/*#################################################
#  						  						           #
#             utils_1.c		           #
#						  						              #
#################################################*/

int		stack_length(t_dll *stack);

t_dll	   *last_item(t_dll *stack);

int      is_sorted(t_dll *stack);

/*#################################################
#  						  						           #
#             utils_2.c		           #
#						  						              #
#################################################*/



int		print_stack_vertical(t_dll *f_i_dll);

int		print_stack_horizontal(t_dll *stack, char *title);

#endif
