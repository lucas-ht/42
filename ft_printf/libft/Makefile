# **************************************************************************** #
#				Vars                                                           #
# **************************************************************************** #

NAME			=	libft.a
PRINT_NAME		=	LIBFT

CC 				=	gcc
CFLAGS 			=	-c -Wall -Wextra -Werror

SOURCES_DIR		=	./sources
BUILD_DIR		=	build

PRINT_PREFIX	=	\033[1m\033[38;5;240m[\033[0m\033[38;5;250m$(PRINT_NAME)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m

# **************************************************************************** #
#				Files                                                          #
# **************************************************************************** #

SRCS			=	ft_strlen.c				ft_write_protect.c			ft_is_base_valid.c		\
					ft_putchar_fd.c			ft_putstr_fd.c				ft_putlong_fd.c			\
					ft_putlong_base_fd.c	ft_putpointer_base_fd.c

OBJS			=	$(SRCS:%.c=$(BUILD_DIR)/%.o)

# **************************************************************************** #
#				Rules                                                          #
# **************************************************************************** #

all:			${NAME}

$(NAME):		$(OBJS)
	@echo "$(PRINT_PREFIX)\033[0;38;5;117m Linking $@\033[0m"
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(PRINT_PREFIX)\033[0;38;5;190m Done !\033[0m\n"

$(OBJS): 		$(BUILD_DIR)/%.o: $(SOURCES_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(PRINT_PREFIX) Compiling \033[0;33m$<\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)

fclean:			clean
	@rm -f ${NAME}

re: 			fclean all

.PHONY: 		all clean
