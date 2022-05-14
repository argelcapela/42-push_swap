.PHONY: all clean fclean re

CC =            clang
CFLAGS = -Wall -Wextra -Werror -ggdb3
AR =            ar -rcs
RM =            rm -rfd

LIBFT_DIR = 	libs/libft
LIBFT.A =       $(LIBFT_DIR)/libft.a


# Mandatory

SRCS_DIR =   	srcs
OBJS_DIR =   	$(SRCS_DIR)/.objs
HEADER_DIR =   ./srcs
HEADER =		$(HEADER_DIR)/push_swap.h
NAME =			push_swap

SRCS_FILES +=	operations/pa.c \
				operations/pb.c \
				operations/ra.c \
				operations/rb.c \
				operations/rr.c \
				operations/rra.c \
				operations/rrb.c \
				operations/rrr.c \
				operations/sa.c \
				operations/sb.c \
				operations/ss.c

SRCS_FILES +=	sort/two.c \
				sort/three.c \
				sort/five.c \
				sort/fit_sort.c

SRCS_FILES +=	steps/1_parse_error.c \
				steps/2_init.c \
				steps/3_sort.c \
				steps/4_impro_effi.c \
				steps/5_print_ops.c \
				steps/6_clear.c

SRCS_FILES +=	utils/ft_dll_op_add_back.c \
				utils/move_to_b.c \
				utils/bring_smaller_to_top.c

SRCS_FILES +=	push_swap.c

SRCS = 			$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS =          $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
	$(CC) -I$(HEADER_DIR) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS_DIR) $(OBJS) $(HEADER)
	make -C $(LIBFT_DIR)
	$(CC) -I$(HEADER_DIR) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT.A)
	@echo "\033[1;32mMANDATORY COMPILED SUCCESFULY!\033[0m"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)/operations
	mkdir -p $(OBJS_DIR)/sort
	mkdir -p $(OBJS_DIR)/steps
	mkdir -p $(OBJS_DIR)/utils

clean:
	$(RM) $(OBJS_DIR)
	@echo "\033[1;32mCLEAN EXECUTED SUCCESFULY!\033[0m"

fclean:	clean
	make fclean -C $(LIBFT_DIR)
	find -name '$(NAME)' -delete
	@echo "\033[1;32mFCLEAN EXECUTED SUCCESFULY!\033[0m"

re:
	@make fclean && make all
	@echo "\033[1;32mRE EXECUTED SUCCESFULY!\033[0m"

tfive: $(NAME)
	@./push_swap `ruby -e "puts (0..11).to_a.shuffle.join(' ')"`
	@echo "\n5 numbers test - movements (limit 12): " && ./push_swap `ruby -e "puts (0..4).to_a.shuffle.join(' ')"` | wc -l

tten: $(NAME)
	@./push_swap 0 7 3 1 2 5 8 4 6 9
	@echo "\n10 numbers test - movements: " && ./push_swap 0 7 3 1 2 5 8 4 6 9 | wc -l

thundred: $(NAME)
	@./push_swap `ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
	@echo "\n100 numbers test - movements (limit 700): " && ./push_swap `ruby -e "puts (0..99).to_a.shuffle.join(' ')"` | wc -l

tfhundred: $(NAME)
	@./push_swap `ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
	@echo "\n500 numbers test - movements (limit 5500): " && ./push_swap `ruby -e "puts (0..499).to_a.shuffle.join(' ')"` | wc -l

# Bonus

SRCS_B_DIR =   	srcs_b
OBJS_B_DIR =   	$(SRCS_B_DIR)/.objs_b
HEADER_B_DIR =  ./srcs_b
HEADER_B =		$(HEADER_B_DIR)/checker.h
NAME_B =		checker

SRCS_B_FILES +=	operations/pa.c \
				operations/pb.c \
				operations/ra.c \
				operations/rb.c \
				operations/rr.c \
				operations/rra.c \
				operations/rrb.c \
				operations/rrr.c \
				operations/sa.c \
				operations/sb.c \
				operations/ss.c

SRCS_B_FILES +=	steps/1_parse_error.c \
				steps/2_init.c \
				steps/3_execute_ops.c \
				steps/4_check_if_ops_sort.c \
				steps/5_clear.c

SRCS_B_FILES +=	utils/ft_dll_op_add_back.c

SRCS_B_FILES +=	checker.c

SRCS_B = 		$(addprefix $(SRCS_B_DIR)/, $(SRCS_B_FILES))
OBJS_B =        $(SRCS_B:$(SRCS_B_DIR)/%.c=$(OBJS_B_DIR)/%.o)
$(OBJS_B_DIR)/%.o:	$(SRCS_B_DIR)/%.c
	$(CC) -I$(HEADER_B_DIR) $(CFLAGS) -c $< -o $@

bonus:	$(NAME_B)

$(NAME_B):	$(OBJS_B_DIR) $(OBJS_B) $(HEADER_B)
	make -C $(LIBFT_DIR)
	$(CC) -I$(HEADER_B_DIR) $(CFLAGS) $(OBJS_B) -o $(NAME_B) $(LIBFT.A)
	@echo "\033[1;32mBONUS COMPILED SUCCESFULY!\033[0m"

$(OBJS_B_DIR):
	mkdir -p $(OBJS_B_DIR)
	mkdir -p $(OBJS_B_DIR)/operations
	mkdir -p $(OBJS_B_DIR)/sort
	mkdir -p $(OBJS_B_DIR)/steps
	mkdir -p $(OBJS_B_DIR)/utils

clean_b:
	$(RM) $(OBJS_B_DIR)
	@echo "\033[1;32mCLEAN_B EXECUTED SUCCESFULY!\033[0m"

fclean_b:	clean_b
	make fclean -C $(LIBFT_DIR)
	find -name '$(NAME_B)' -delete
	@echo "\033[1;32mFCLEAN_B EXECUTED SUCCESFULY!\033[0m"

re_b:
	@make fclean_b && make bonus
	@echo "\033[1;32mRE_B EXECUTED SUCCESFULY!\033[0m"

fclean_all:	clean clean_b
	make fclean -C $(LIBFT_DIR)
	find -name '$(NAME)' -delete
	find -name '$(NAME_B)' -delete
	@echo "\033[1;32mFCLEAN AND FCLEAN_B EXECUTED SUCCESFULY!\033[0m"

re_all:
	@make fclean && make
	@make fclean_b && make bonus
	@echo "\033[1;32mRE AND RE_B EXECUTED SUCCESFULY!\033[0m"
