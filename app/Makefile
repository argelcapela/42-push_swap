.PHONY: all clean fclean re

CC =            clang
HEADERS_DIR =   ./includes
CFLAGS =		-I$(HEADERS_DIR) -Wall -Wextra -Werror -ggdb3
AR =            ar -rcs
RM =            rm -rfd
LIBFT_DIR = 	libs/libft
LIBFT.A =       $(LIBFT_DIR)/libft.a

NAME =			push_swap
SRCS_DIR =   	srcs
OBJS_DIR =   	.objs
HEADER =		./includes/push_swap.h

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

SRCS = 			$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS =          $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS_DIR) $(OBJS) $(HEADER)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT.A)
	@echo "\033[1;32mMANDATORY COMPILED SUCCESFULY!\033[0m"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)/6_sort
	mkdir -p $(OBJS_DIR)/6_sort/1_sort_utils
	mkdir -p $(OBJS_DIR)/6_sort/2_stack_basic_operations

clean:
	$(RM) $(OBJS_DIR)
	@echo "\033[1;32mCLEAN EXECUTED SUCCESFULY!\033[0m"

fclean:	clean
	find -name '$(NAME)' -delete
	@echo "\033[1;32mFCLEAN EXECUTED SUCCESFULY!\033[0m"

re:
	@make fclean && make all
	@echo "\033[1;32mRE EXECUTED SUCCESFULY!\033[0m"
