/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:03:14 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/18 16:51:11 by acapela-         ###   ########.fr       */
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
# include "../libft/libft.h"

/*#################################################
#  						  						           #
#   				macros	  					           #
#						  						              #
#################################################*/

# define INT_MAX 2147483647

# define INT_MIN 2147483648

/*#################################################
#  						  						           #
#   				structs	  				              #
#						  						              #
#################################################*/

/* 
   dll means: 'D'ouble 'L'inked 'L'ist 
   a data structure used here on push swap
   to hold the values of some stack and 
   after work with them in an eficient way.
*/

typedef struct s_dll
{
	struct s_dll	*previous_item;
	struct s_dll	*next_item;
	int				value;
}	t_dll;

typedef struct s_push_swap
{
   int            argc;
   char**         argv;
   int            n;
	struct s_dll   *stack_a;
   struct s_dll   *stack_b;
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

int      init_push_swap(t_push_swap *push_swap);

/*#################################################
#  						  						           #
#   		    5_execute_push_swap.c  	           #
#						  						              #
#################################################*/

int      execute_push_swap(t_push_swap *push_swap);

/*#################################################
#  						  						           #
#   			  6_basic_movements			           #
#						  						              #
#################################################*/

void     ra(t_push_swap *push_swap);

void     rb(t_push_swap *push_swap);

void     rr(t_push_swap *push_swap);

void     rra(t_push_swap *push_swap);

void     rrb(t_push_swap *push_swap);

void     rrr(t_push_swap *push_swap);

void     sa(t_push_swap *push_swap);

void     sb(t_push_swap *push_swap);

void     ss(t_push_swap *push_swap);

void     pa(t_push_swap *push_swap);

void     pb(t_push_swap *push_swap);

/*#################################################
#  						  						           #
#      7_sort_with_least_amount_of_movements      #
#						  						              #
#################################################*/

void     sort_2_numbers(t_push_swap *push_swap);

void     sort_2_numbers_b(t_push_swap *push_swap);

void     sort_3_numbers(t_push_swap *push_swap);

void     sort_5_numbers(t_push_swap *push_swap);

void     sort_100_numbers(t_push_swap *push_swap);

void     sort_more_than_100_numbers(t_push_swap *push_swap);

/*#################################################
#  						  						           #
#             8_push_swap_utils_1.c		           #
#						  						              #
#################################################*/

int		print_stack_vertical(t_dll *f_i_dll);

int		print_stack_horizontal(t_dll *stack, char *title);

int		stack_length(t_dll *stack);

t_dll	   *get_last_item(t_dll *stack);

void	   reverse_stack(t_dll *stack, t_push_swap *push_swap);

/*#################################################
#  						  						           #
#             8_push_swap_utils_2.c		           #
#						  						              #
#################################################*/

int      stack_already_is_sorted(t_push_swap *push_swap);

#endif