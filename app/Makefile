# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 01:45:50 by acapela-          #+#    #+#              #
#    Updated: 2022/05/06 20:16:51 by acapela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			push_swap
NAME_B =		push_swap_b

HEADER =		./includes/push_swap.h
HEADER_B = 		./includes/push_swap_b.h

SRCS_FILES=		1_main.c \
				2_push_swap.c \
				3_identify_errors.c \
				4_init_push_swap.c \
				5_execute_push_swap.c \
				7_clear.c

SRCS_FILES +=	6_sort/1_sort_utils/sort_utils_1.c

SRCS_FILES +=	6_sort/2_stack_basic_operations/pa.c \
				6_sort/2_stack_basic_operations/pb.c \
				6_sort/2_stack_basic_operations/ra.c \
				6_sort/2_stack_basic_operations/rb.c \
				6_sort/2_stack_basic_operations/rr.c \
				6_sort/2_stack_basic_operations/rra.c \
				6_sort/2_stack_basic_operations/rrb.c \
				6_sort/2_stack_basic_operations/rrr.c \
				6_sort/2_stack_basic_operations/sa.c \
				6_sort/2_stack_basic_operations/sb.c \
				6_sort/2_stack_basic_operations/ss.c

SRCS_FILES +=	6_sort/3_sort.c \
				6_sort/4_sort_2_numbers.c \
				6_sort/5_sort_3_numbers.c \
				6_sort/6_sort_5_numbers.c \
				6_sort/7_sort_more_than_5_numbers.c

SRCS_FOLDER =   srcs
OBJS_FOLDER =   .objs

SRCS = 			$(addprefix $(SRCS_FOLDER)/, $(SRCS_FILES))
OBJS =          $(SRCS:$(SRCS_FILES)/%.c=$(OBJ_FOLDER)/%.o)

LIBFT.A =       libs/libft/libft.a
LIBFT_FOLDER =  libs/libft

CC =            clang
CFLAGS =		-Wall -Wextra -Werror -ggdb3
INCLUDES =      ./includes
AR =             ar -rcs
RM =             rm -rfd

$(OBJS_FOLDER)/%.o: $(SRCS_DIR)/%.c $(HEADER)
				$(CC) -I$(INCLUDES) $(CFLAGS) -c $<	-o $@

$(OBJS_FOLDER)/%.o: $(BONUS_DIR)/%.c $(HEADER_BONUS)
				$(CC) -I$(INCLUDES) $(CFLAGS) -c $<	-o $@

all:
				echo $(OBJS)
#$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(LIBFT) $(OBJS_FOLDER) $(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT.A) -o $(NAME)
				@echo "\033[1;32m\nMANDATORY COMPILED SUCCESFULY!\033[0m\n\n"

$(OBJS_FOLDER):
				mkdir -p $(OBJS_FOLDER)

$(LIBFT):
				$(MAKE) -C $(LIBFT_FOLDER)

clean:
				$(MAKE) -C $(LIBFT_FOLDER) clean
				$(RM) $(OBJS)

fclean:			clean
				rm -rfd $(NAME)
				$(MAKE) -C $(LIBFT_FOLDER) fclean
				$(RM) $(NAME) $(NAME_BONUS)
				echo "\033[1;32m\nFCLEAN MANDATORY EXECUTED SUCCESFULY!\033[0m\n\n"

re:				fclean all

.PHONY:			clean fclean re
