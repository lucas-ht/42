# **************************************************************************** #
#				Vars                                                           #
# **************************************************************************** #

NAME			=	server
PRINT_NAME		=	MINITALK

SOURCES_DIR		=	./sources
BUILD_DIR		=	./build

LIBFT			=	$(LIBFT_DIR)/libft.a
LIBFT_DIR		=	./libft

PRINT_PREFIX	=	\033[1m\033[38;5;240m[\033[0m\033[38;5;250m$(PRINT_NAME)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m

# **************************************************************************** #
#				Rules                                                          #
# **************************************************************************** #

all:			$(NAME)	

$(NAME):		$(LIBFT)
	@make -C $(SOURCES_DIR)/client
	@make -C $(SOURCES_DIR)/server
	@echo "$(PRINT_PREFIX)\033[0;38;5;190m Done !\033[0m\n"

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Cleaning \033[0m\n"
	@rm -rf $(BUILD_DIR)

fclean:			clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f client
	@rm -f server

re: 			fclean all

.PHONY:			all clean
