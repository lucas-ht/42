# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Vars                                                                                                        #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

NAME			=	fdf
PRINT_NAME		=	FDF

CC 				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

INCLUDES_DIR	=	./includes/
SOURCES_DIR		=	./sources/

LIBFT_DIR		=	./libft/
LIBFT			=	$(LIBFT_DIR)libft.a
LIB				=	-I $(LIBFT_DIR) -L $(LIBFT_DIR) -lft

LIBMLX_DIR		=	./MLX42/
LIBMLX			=	$(LIBFT_DIR)libmlx42.a
MLX				=	-L MLX42 -lmlx -I MLX42/Include -framework OpenGL -framework AppKit

MATH			=	-lm

PRINT_PREFIX	=	\033[1m\033[38;5;240m[\033[0m\033[38;5;250m$(PRINT_NAME)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m
T 				=	1

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Files                                                                                                       #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

SRCS			=	fdf.c																							\
																													\
					parser.c						map.c															\
					drawer.c						projection.c					hook.c							\
																													\
					error.c

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Rules                                                                                                       #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

all:			 title $(LIBMLX) $(LIBFT) $(NAME)
	@:
	@echo "$(PRINT_PREFIX)\033[0;38;5;190m Done !\033[0m\n"

$(NAME):
	@$(foreach s,$(SRCS),echo "$(PRINT_PREFIX) Compiling \033[0;33m$(s)\033[0m";)
	@$(CC) $(CFLAGS) $(addprefix $(SOURCES_DIR), $(SRCS)) -I $(INCLUDES_DIR) $(LIB) $(MLX) $(MATH) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(LIBMLX):
	@echo "$(PRINT_PREFIX) Compiling \033[0;33mMLX\033[0m"
	@make -C $(LIBMLX_DIR) &>/dev/null
	@echo "$(PRINT_PREFIX)\033[0;38;5;190m Done !\033[0m\n"

clean:			title
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Cleaning \033[0m\n"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(LIBMLX_DIR) &>/dev/null

fclean:			clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: 			fclean all

bonus:			all

.PHONY:			all

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Style                                                                                                       #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

title:
ifeq ($(T), 1)
	$(call title,$(PRINT_NAME))
	@T=0
endif

define title
	@echo "\033[38;5;240m━━━━━━━━━━━━━━━━━━━━━━\033[0m $(1) \033[38;5;240m━━━━━━━━━━━━━━━━━━━━━━\033[0m\n";
endef
