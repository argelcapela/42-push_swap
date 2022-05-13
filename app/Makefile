.PHONY: all clean fclean re

CC =            clang
CFLAGS = -Wall -Wextra -Werror -ggdb3
AR =            ar -rcs
RM =            rm -rfd

LIBFT_DIR = 	libs/libft
LIBFT.A =       $(LIBFT_DIR)/libft.a

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
				sort/one_hundred.c \
				sort/five_hundred.c

SRCS_FILES +=	steps/1_parse_error.c \
				steps/2_init.c \
				steps/3_sort.c \
				steps/4_clear.c

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
	@./push_swap `ruby -e "puts (0..9).to_a.shuffle.join(' ')"`
	@echo "\n10 numbers test - movements: " && ./push_swap `ruby -e "puts (0..9).to_a.shuffle.join(' ')"` | wc -l

thundred: $(NAME)
	@./push_swap `ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
	@echo "\n100 numbers test - movements (limit 700): " && ./push_swap `ruby -e "puts (0..99).to_a.shuffle.join(' ')"` | wc -l

tfhundred: $(NAME)
	@./push_swap `ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
	@echo "\n500 numbers test - movements (limit 5500): " && ./push_swap `ruby -e "puts (0..499).to_a.shuffle.join(' ')"` | wc -l
