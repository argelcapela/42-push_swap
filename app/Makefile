# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 01:45:50 by acapela-          #+#    #+#              #
#    Updated: 2022/04/14 18:27:01 by acapela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			push_swap

NAME_B =		push_swap_b

HEADER =		srcs/push_swap.h

HEADER_B = 		srcs_b/push_swap_b.h

VPATH =			srcs/

SRCS =			1_main.c \
				2_push_swap.c \
				3_identify_errors.c \
				4_init_push_swap.c \
				5_execute_push_swap.c

SRCS +=			pa.c \
				pb.c \
				ra.c \
				rb.c \
				rr.c \
				rra.c \
				rrb.c \
				rrr.c \
				sa.c \
				sb.c \
				ss.c 
				
SRCS +=			8_push_swap_utils.c 

SRCS_B =		


OBJS =          $(SRCS:%.c=%.o)

OBJS_B =		$(SRCS_B:%.c=srcs_b/.objs/%.o)

OBJS_FOLDER =   srcs/.objs


LIBFT.A =       libft/libft.a


CC =            clang

CFLAGS =		-Wall -Wextra -Werror -ggdb3

AR =             ar -rcs


all:			$(NAME)

$(NAME):		$(OBJS) $(HEADER)
				$(MAKE) -C libft
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT.A)  -I./srcs
				@mkdir -p $(OBJS_FOLDER)
				mv *.o srcs/.objs
				@echo "\033[1;32m\nMANDATORY COMPILED SUCCESFULY!\033[0m\n\n"

%.o: 			%.c $(HEADER)
				$(CC) $(CFLAGS) -c $<	-o $@		

clean:
				rm -rfd srcs/.objs
				
fclean:			
				@$(MAKE) clean 2>/dev/null || true
				@$(MAKE) fclean -C libs/libft 2>/dev/null || true
				@rm -rfd push_swap 2>/dev/null || true
				@echo "\033[1;32m\nFCLEAN MANDATORY EXECUTED SUCCESFULY!\033[0m\n\n"

fclean_bonus:
				@$(MAKE) clean 2>/dev/null || true
				@$(MAKE) fclean -C libs/libft 2>/dev/null || true
				@rm -rfd  2>/dev/null || true
				@echo "\033[1;32m\nFCLEAN BONUS EXECUTED SUCCESFULY!\033[0m\n\n"	

re:				fclean all

re_bonus:		fclean_bonus bonus

n:			
				norminette *

.PHONY:			clean fclean fclean_bonus re re_bonus n

