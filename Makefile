# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Vars                                                                                                        #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

NAME			=	push_swap
PRINT_NAME		=	PUSH_SWAP

SOURCES_DIR		=	./sources
BUILD_DIR		=	./build

LIBFT_DIR		=	./libft
LIBFT			=	$(LIBFT_DIR)/libft.a

PRINT_PREFIX	=	\033[1m\033[38;5;240m[\033[0m\033[38;5;250m$(PRINT_NAME)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m
T 				=	1

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Rules                                                                                                       #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

all:			$(NAME)

$(NAME):		title $(LIBFT)
	@make -C $(SOURCES_DIR)/common
	@make -C $(SOURCES_DIR)/push_swap
	@echo "$(PRINT_PREFIX)\033[0;38;5;190m Done !\033[0m\n"

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:			title
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Cleaning \033[0m\n"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(BUILD_DIR)

fclean:			clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@rm -f checker

bonus:			all
	$(call title,"$(PRINT_NAME) BONUS")
	@make -C $(SOURCES_DIR)/checker

re: 			fclean all

.PHONY:			all

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Style                                                                                                       #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

define center
	@printf "%*b\n" $$((($${COLUMNS:-$$(tput cols)}+$${#$1})/2)) "$(1)";
endef

title:
ifeq ($(T), 1)
	$(call title,$(PRINT_NAME))
	@T=0
endif

define title
	@echo "\033[38;5;240m━━━━━━━━━━━━━━━━━━━━━━\033[0m $(1) \033[38;5;240m━━━━━━━━━━━━━━━━━━━━━━\033[0m\n";
endef
