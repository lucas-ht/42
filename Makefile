# **************************************************************************** #
#				Vars                                                           #
# **************************************************************************** #

NAME			=	libftprintf.a
PRINT_NAME		=	FT_PRINTF

CC 				=	gcc
CFLAGS 			=	-c -Wall -Wextra -Werror

INCLUDES_DIR	=	./includes
SOURCES_DIR		=	./sources
BUILD_DIR		=	./build

LIBFT_DIR		=	./libft
LIBFT			=	$(LIBFT_DIR)/libft.a

TEST_FILE		=	main.c
TEST_LIB		=	$(shell echo $(NAME) | sed -e "s/^lib//" -e "s/.a$$//")
TEST_OUTPUT		=	test.out

PRINT_PREFIX	=	\033[1m\033[38;5;240m[\033[0m\033[38;5;250m$(PRINT_NAME)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m

# **************************************************************************** #
#				Files                                                          #
# **************************************************************************** #

SRCS			=	ft_printf.c		ft_types1.c		ft_types2.c

OBJS			=	$(SRCS:%.c=$(BUILD_DIR)/%.o)

# **************************************************************************** #
#				Rules                                                          #
# **************************************************************************** #

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJS)
	@echo "$(PRINT_PREFIX)\033[0;38;5;117m Linking $@\033[0m"
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(PRINT_PREFIX)\033[0;38;5;190m Done !\033[0m\n"

$(OBJS):		$(BUILD_DIR)/%.o: $(SOURCES_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(PRINT_PREFIX) Compiling \033[0;33m$<\033[0m"
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -I $(LIBFT_DIR) $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Cleaning \033[0m\n"
	@rm -rf $(BUILD_DIR)

fclean:			clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f ${NAME}

re: 			fclean all

test:			re
	@echo "$(PRINT_PREFIX) Compiling\033[0;33m $(TEST_FILE)\033[0m"
	@$(CC) $(TEST_FILE) -I $(INCLUDES_DIR) -L. -l$(TEST_LIB) -o $(TEST_OUTPUT)
	@echo "$(PRINT_PREFIX)\033[0;38;5;219m Testing\033[0m"
	@./$(TEST_OUTPUT)
	@rm -f $(TEST_OUTPUT)
	@echo "\n$(PRINT_PREFIX)\033[0;38;5;190m Done !\033[0m\n"

.PHONY:			all clean
