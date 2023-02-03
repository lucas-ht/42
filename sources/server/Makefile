# **************************************************************************** #
#				Vars                                                           #
# **************************************************************************** #

NAME			=	server
NAME_EXEC		=	server.c

NAME_LIB		=	lib$(NAME).a

PRINT_NAME		=	MINITALK SERVER

CC 				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS_LIB		=	-c $(CFLAGS)

ROOT_DIR		=	./../../

INCLUDES_DIR	=	$(ROOT_DIR)/includes
BUILD_DIR		=	$(ROOT_DIR)/build/$(NAME)

LIBFT_DIR		=	$(ROOT_DIR)/libft
LIBFT_LIB		=	ft

PRINT_PREFIX	=	\033[1m\033[38;5;240m[\033[0m\033[38;5;250m$(PRINT_NAME)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m

# **************************************************************************** #
#				Files                                                          #
# **************************************************************************** #

SRCS			=	handler.c

OBJS			=	$(SRCS:%.c=$(BUILD_DIR)/%.o)

# **************************************************************************** #
#				Rules                                                          #
# **************************************************************************** #

all:			$(NAME_LIB) $(NAME)

$(NAME_LIB):	$(OBJS)
	@echo "$(PRINT_PREFIX)\033[0;38;5;117m Linking $@\033[0m"
	@ar -rcs $(BUILD_DIR)/$(NAME_LIB) $(OBJS)

$(OBJS):		$(BUILD_DIR)/%.o: ./%.c
	@mkdir -p $(@D)
	@echo "$(PRINT_PREFIX) Compiling \033[0;33m$<\033[0m"
	@$(CC) $(CFLAGS_LIB) -I $(INCLUDES_DIR) -I $(LIBFT_DIR)  $< -o $@

$(NAME):
	@echo "$(PRINT_PREFIX) Compiling\033[0;33m $(NAME_EXEC)\033[0m"
	@$(CC) $(FLAGS_LIB) $(NAME_EXEC) -I $(INCLUDES_DIR) -I $(LIBFT_DIR) -L $(BUILD_DIR) -l$(NAME) -L $(LIBFT_DIR) -l$(LIBFT_LIB) -o $(ROOT_DIR)$(NAME)
	@echo "$(PRINT_PREFIX)\033[0;38;5;190m Done !\033[0m\n"

re: 			fclean all

.PHONY:			all clean
