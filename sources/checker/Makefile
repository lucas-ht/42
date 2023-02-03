# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Vars                                                                                                        #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

NAME			=	checker
PRINT_NAME		=	PUSH_SWAP CH

CC 				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

ROOT_DIR		=	./../../
INCLUDES_DIR	=	$(ROOT_DIR)/includes/
BUILD_DIR		=	$(ROOT_DIR)/build/

LIBFT_DIR		=	$(ROOT_DIR)/libft/
LIB				=	-I $(LIBFT_DIR) -L $(LIBFT_DIR) -lft

LIB_CM			=	-lcm

PRINT_PREFIX	=	\033[1m\033[38;5;240m[\033[0m\033[38;5;250m$(PRINT_NAME)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Files                                                                                                       #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

SRCS			=	reader.c																					\

OBJS			=	$(SRCS:%.c=$(BUILD_DIR)%.o)

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Rules                                                                                                       #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

all:			$(BUILD_DIR)lib$(NAME).a $(ROOT_DIR)$(NAME)
	@:

$(BUILD_DIR)lib$(NAME).a:	$(OBJS)
	@echo "$(PRINT_PREFIX)\033[0;38;5;117m Linking lib$(NAME).a\033[0m"
	@ar -rcs $(BUILD_DIR)lib$(NAME).a $(OBJS)

$(OBJS):		$(BUILD_DIR)%.o: ./%.c
	@mkdir -p $(@D)
	@echo "$(PRINT_PREFIX) Compiling \033[0;33m$<\033[0m"
	@$(CC) -c $(CFLAGS) -I $(INCLUDES_DIR) -I $(LIBFT_DIR) $< -o $@

$(ROOT_DIR)$(NAME):
	@echo "$(PRINT_PREFIX) Compiling\033[0;33m $(NAME).c\033[0m"
	@$(CC) $(CFLAGS) $(NAME).c -I $(INCLUDES_DIR) $(LIB) $(LIB_CM) -L $(BUILD_DIR) -l$(NAME) -o $(ROOT_DIR)$(NAME)
	@echo "$(PRINT_PREFIX)\033[0;38;5;190m Done !\033[0m\n"

.PHONY:			all
