/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:03:14 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/09 07:03:49 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*#################################################
#  						  						  #
#   				libs	  					  #
#						  						  #
#################################################*/

// malloc, free
# include <stdlib.h>

// read, write
# include <unistd.h>

// libft, get_next_line, ft_printf, etc..
# include "../libs/libft/libft.h"

/*#################################################
#  						  						  #
#   				macros	  					  #
#						  						  #
#################################################*/

/*#################################################
#  						  						  #
#   				structs	  					  #
#						  						  #
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
	struct s_dll   *f_i_stack_a;
   struct s_dll   *f_i_stack_b;
}	t_push_swap;


/*#################################################
#  						  						  #
#   			  2_push_swap.c 				  #
#						  						  #
#################################################*/

int		push_swap(int argc, char **argv);

/*#################################################
#  						  						  #
#   			  3_ 				              #
#						  						  #
#################################################*/

int	   identify_erros(int argc, char **argv);

/*#################################################
#  						  						  #
#   			  4_             				  #
#						  						  #
#################################################*/

int      prepare_to_sort(t_push_swap *push_swap);

#endif