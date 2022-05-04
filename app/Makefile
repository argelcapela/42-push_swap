# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 01:45:50 by acapela-          #+#    #+#              #
#    Updated: 2022/05/04 02:16:28 by acapela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			push_swap

NAME_B =		push_swap_b

HEADER =		./includes/push_swap.h

HEADER_B = 		./includes/push_swap_b.h

SRCS =			srcs/1_main.c \
				srcs/2_push_swap.c \
				srcs/3_identify_errors.c \
				srcs/4_init_push_swap.c \
				srcs/5_execute_push_swap.c

SRCS +=			srcs/6_sort/1_sort_utils/sort_utils_1.c \
				srcs/6_sort/1_sort_utils/sort_utils_2.c

SRCS +=			srcs/6_sort/2_stack_basic_operations/pa.c \
				srcs/6_sort/2_stack_basic_operations/pb.c \
				srcs/6_sort/2_stack_basic_operations/ra.c \
				srcs/6_sort/2_stack_basic_operations/rb.c \
				srcs/6_sort/2_stack_basic_operations/rr.c \
				srcs/6_sort/2_stack_basic_operations/rra.c \
				srcs/6_sort/2_stack_basic_operations/rrb.c \
				srcs/6_sort/2_stack_basic_operations/rrr.c \
				srcs/6_sort/2_stack_basic_operations/sa.c \
				srcs/6_sort/2_stack_basic_operations/sb.c \
				srcs/6_sort/2_stack_basic_operations/ss.c

SRCS +=			srcs/6_sort/3_sort.c \
				srcs/6_sort/4_sort_2_numbers.c \
				srcs/6_sort/5_sort_3_numbers.c \
				srcs/6_sort/6_sort_5_numbers.c \
				srcs/6_sort/7_sort_more_than_5_numbers.c 

SRCS_B =

OBJS =          $(SRCS:%.c=%.o)
OBJS_FOLDER =   .objs

LIBFT.A =       libs/libft/libft.a
LIBFT_FOLDER =  libs/libft

CC =            clang
CFLAGS =		-Wall -Wextra -Werror -ggdb3
INCLUDES = ./includes
AR =             ar -rcs

all:			$(NAME)

$(NAME):		$(OBJS) $(HEADER)
				$(MAKE) -C $(LIBFT_FOLDER)
				$(CC) $(CFLAGS)  -o $(NAME) $(OBJS) $(LIBFT.A)
				@echo "\033[1;32m\nMANDATORY COMPILED SUCCESFULY!\033[0m\n\n"

%.o: 			%.c $(HEADER)
				$(CC) -I$(INCLUDES) $(CFLAGS) -c $<	-o $@

clean:
				rm -rfd $(OBJS)

fclean:
				rm -rfd $(NAME)
				$(MAKE) clean
				$(MAKE) fclean -C $(LIBFT_FOLDER)
				echo "\033[1;32m\nFCLEAN MANDATORY EXECUTED SUCCESFULY!\033[0m\n\n"

fclean_bonus:
				rm -rfd  $(NAME_B)
				$(MAKE) clean
				$(MAKE) fclean -C $(LIBFT_FOLDER)
				echo "\033[1;32m\nFCLEAN BONUS EXECUTED SUCCESFULY!\033[0m\n\n"

re:				fclean all

re_bonus:		fclean_bonus bonus

n:
				norminette *

.PHONY:			clean fclean fclean_bonus re re_bonus n

