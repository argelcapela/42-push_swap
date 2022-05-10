4

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
