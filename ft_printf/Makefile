NAME		=	libftprintf.a


# *******************************************************************************************************************
#				Files
# *******************************************************************************************************************

SRCS		=	ft_printf.c		ft_types1.c		ft_types2.c

OBJS		=	${SRCS:.c=.o}

# *******************************************************************************************************************
#				Rules
# *******************************************************************************************************************

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o} -I includes

${NAME}: ${OBJS}
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all:	${NAME}

clean:
	$(MAKE) clean -C ./libft
	rm -f ${OBJS} $(BONUS_OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f ${NAME}

re: 	fclean all