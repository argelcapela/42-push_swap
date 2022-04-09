# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 01:45:50 by acapela-          #+#    #+#              #
#    Updated: 2022/04/09 04:01:19 by acapela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			push_swap

NAME_B =		push_swap_b

HEADER =		srcs/push_swap.h

HEADER_B = 		srcs_b/push_swap_b.h


SRCS =			1_main.c \
				2_push_swap.c \
				3_identify_errors.c \
				4_prepare_to_sort.c

SRCS_B =		


OBJS =          $(SRCS:%.c=srcs/.objs/%.o)

OBJS_B =		$(SRCS_B:%.c=srcs_b/.objs/%.o)

OBJS_FOLDER =   srcs/.objs


LIBFT.A =       libs/libft/libft.a


CC =            clang

CFLAGS =		-Wall -Wextra -Werror -ggdb3

AR =             ar -rcs


all:			$(NAME)

$(NAME):		$(OBJS_FOLDER) $(OBJS) $(HEADER)
				$(MAKE) -C libs/libft
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT.A)  -I./srcs
				@echo "\033[1;32m\nMANDATORY COMPILED SUCCESFULY!\033[0m\n\n"

srcs/.objs/%.o: 		srcs/%.c $(HEADER)
				$(CC) $(CFLAGS) -c $<	-o $@


bonus:			$(NAME_B)

$(NAME_B):		$(OBJS_FOLDER) $(OBJS_B) $(HEADER_B)
				$(MAKE) -C libs/libft
				$(CC) $(CFLAGS) -o $(NAME_B) $(OBJS_B) $(LIBFT.A)  -I./srcs_b
				@echo "\033[1;32m\nBONUS COMPILED SUCCESFULY!\033[0m\n\n"

srcs_b/.objs/%.o: 		srcs_b/%.c $(HEADER_B)
				$(CC) $(CFLAGS) -c $<	-o $@

$(OBJS_FOLDER):
				@mkdir -p $(OBJS_FOLDER)

clean:
				rm -rfd $(OBJS_B) $(OBJS) .objs leak.txt
				
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

