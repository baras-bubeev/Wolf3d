# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 14:08:27 by baras             #+#    #+#              #
#    Updated: 2021/01/25 14:55:22 by mpowder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	window.c

OBJS	= ${SRCS:.c=.o}

NAME	= cub3d

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

MLX		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(NAME):	${OBJS}
			$(CC) -o $(NAME) $(OBJS) $(MLX)

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re