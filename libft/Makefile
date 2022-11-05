# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 22:52:18 by lhutt             #+#    #+#              #
#    Updated: 2022/11/05 02:49:55 by lhutt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a


# *******************************************************************************************************************
#				Files
# *******************************************************************************************************************

SRCS		=	ft_isalpha.c		ft_isdigit.c		ft_isalnum.c		ft_isascii.c		ft_isprint.c		\
				ft_strlen.c			ft_memset.c			ft_bzero.c			ft_memcpy.c			ft_memmove.c		\
				ft_strlcpy.c		ft_strlcat.c		ft_tolower.c		ft_toupper.c		ft_strchr.c			\
				ft_strrchr.c		ft_strncmp.c 		ft_memchr.c			ft_memcmp.c			ft_strnstr.c		\
				ft_atoi.c			ft_calloc.c			ft_strdup.c			ft_substr.c			ft_strjoin.c		\
				ft_strtrim.c		ft_split.c			ft_itoa.c			ft_strmapi.c		ft_striteri.c		\
				ft_putchar_fd.c		ft_putstr_fd.c		ft_putendl_fd.c		ft_putnbr_fd.c

OBJS		=	${SRCS:.c=.o}


# *******************************************************************************************************************
#				Bonus Files
# *******************************************************************************************************************

BONUS_SRCS	=	ft_lstnew.c			ft_lstadd_front.c	ft_lstsize.c		ft_lstlast.c		ft_lstadd_back.c	\
				ft_lstdelone.c		ft_lstclear.c		ft_lstiter.c		ft_lstmap.c

BONUS_OBJS	=	${BONUS_SRCS:.c=.o}


# *******************************************************************************************************************
#				Rules
# *******************************************************************************************************************

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o} -I includes

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all:	${NAME}

bonus:	$(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)
	ranlib ${NAME}

clean:
	rm -f ${OBJS} $(BONUS_OBJS)

fclean: clean
	rm -f ${NAME}

re: 	fclean all