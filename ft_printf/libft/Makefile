NAME		=	libft.a


# *******************************************************************************************************************
#				Files
# *******************************************************************************************************************

SRCS		=	ft_strlen.c				ft_write_protect.c			ft_is_base_valid.c		\
				ft_putchar_fd.c			ft_putstr_fd.c				ft_putlong_fd.c			\
				ft_putlong_base_fd.c	ft_putpointer_base_fd.c

OBJS		=	${SRCS:.c=.o}


# *******************************************************************************************************************
#				Rules
# *******************************************************************************************************************

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o} -I includes

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all:	${NAME}

clean:
	rm -f ${OBJS} $(BONUS_OBJS)

fclean: clean
	rm -f ${NAME}

re: 	fclean all
