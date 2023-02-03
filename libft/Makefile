# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Vars                                                                                                        #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

NAME			=	libft.a
PRINT_NAME		=	LIBFT

CC 				=	gcc
CFLAGS 			=	-c -Wall -Wextra -Werror

INCLUDES_DIR	=	./includes
SOURCES_DIR		=	./sources
BUILD_DIR		=	./build

TEST_FILE		=	main.c
TEST_LIB		=	$(shell echo $(NAME) | sed -e "s/^lib//" -e "s/.a$$//")
TEST_OUTPUT		=	test.out

PRINT_PREFIX	=	\033[1m\033[38;5;240m[\033[0m\033[38;5;250m$(PRINT_NAME)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Files                                                                                                       #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

SRCS			=	ctype/ft_isalpha.c				ctype/ft_isdigit.c				ctype/ft_isalnum.c			\
					ctype/ft_isascii.c				ctype/ft_isprint.c				ctype/ft_toupper.c			\
					ctype/ft_tolower.c				ctype/ft_isnumber.c				ctype/ft_isint.c			\
																												\
					string/ft_strlen.c				string/ft_memset.c				string/ft_bzero.c			\
					string/ft_memcpy.c				string/ft_memmove.c				string/ft_strlcpy.c			\
					string/ft_strlcat.c				string/ft_strchr.c				string/ft_strrchr.c			\
					string/ft_strncmp.c				string/ft_memchr.c				string/ft_memcmp.c			\
					string/ft_strnstr.c				string/ft_strdup.c											\
																												\
					stdlib/ft_atoi.c				stdlib/ft_calloc.c											\
																												\
					ft/ft_substr.c					ft/ft_strjoin.c					ft/ft_strtrim.c				\
					ft/ft_split.c					ft/ft_itoa.c					ft/ft_strmapi.c				\
					ft/ft_striteri.c				ft/ft_is_base_valid.c			ft/ft_free_split.c			\
					ft/ft_striter_if.c																			\
																												\
					put/ft_putchar_fd.c				put/ft_putstr_fd.c				put/ft_putendl_fd.c			\
					put/ft_putnbr_fd.c				put/ft_putlong_fd.c				put/ft_putlong_base_fd.c	\
					put/ft_putpointer_base_fd.c		put/ft_write_protect.c										\
																												\
					list/ft_lstnew.c				list/ft_lstadd_front.c			list/ft_lstsize.c			\
					list/ft_lstlast.c				list/ft_lstadd_back.c			list/ft_lstdelone.c			\
					list/ft_lstclear.c				list/ft_lstiter.c				list/ft_lstmap.c			\
																												\
					list2/ft_lstnew2.c				list2/ft_lstadd_front2.c		list2/ft_lstsize2.c			\
					list2/ft_lstlast2.c				list2/ft_lstadd_back2.c			list2/ft_lstdelone2.c		\
					list2/ft_lstclear2.c			list2/ft_lstiter2.c				list2/ft_lstmap2.c			\
					list2/ft_lstprint2.c			list2/ft_lstat2.c											\
																												\
					gnl/get_next_line.c																			\
																												\
					printf/ft_printf.c				printf/ft_types1.c				printf/ft_types2.c			\


OBJS			=	$(SRCS:%.c=$(BUILD_DIR)/%.o)

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Rules                                                                                                       #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

all:			$(NAME)

$(NAME):		$(OBJS)
	@echo "$(PRINT_PREFIX)\033[0;38;5;117m Linking $@\033[0m"
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(PRINT_PREFIX)\033[0;38;5;190m Done !\033[0m\n"

$(OBJS): 		$(BUILD_DIR)/%.o: $(SOURCES_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(PRINT_PREFIX) Compiling \033[0;33m$<\033[0m"
	@$(CC) $(CFLAGS) -I . -I $(INCLUDES_DIR) $< -o $@

clean:
	@rm -rf $(BUILD_DIR)

fclean:			clean
	@rm -f $(NAME)

re: 			fclean all

test:			re
	@echo "$(PRINT_PREFIX) Compiling\033[0;33m $(TEST_FILE)\033[0m"
	@$(CC) $(TEST_FILE) -I . -I $(INCLUDES_DIR) -L. -l$(TEST_LIB) -o $(TEST_OUTPUT)
	@echo "$(PRINT_PREFIX)\033[0;38;5;219m Testing\033[0m"
	@./$(TEST_OUTPUT)
	@rm -f $(TEST_OUTPUT)
	@echo "\n$(PRINT_PREFIX)\033[0;38;5;190m Done !\033[0m\n"

.PHONY: 		all clean
