SRCS	=	main.c \
			srcs/draw_minimap.c \
			srcs/exit.c \
			srcs/keypress.c \
			srcs/map_validation.c \
			srcs/my_pixel_put.c \
			srcs/parsing.c \
			srcs/raycast.c \
			srcs/screen.c \
			srcs/sprite.c \
			srcs/texture.c \
			srcs/var_init.c \
			srcs/window.c

OBJS	= ${SRCS:.c=.o}

NAME	= wolf_3D

CC		= gcc

RM		= rm -f

CFLAGS	= -g -fsanitize=address -Wall -Wextra -Werror

MLX		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

.c.o:
			${CC} ${CFLAGS} -I. -Imlx_linux -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@make -C libft/
			@make -C mlx_linux/
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} libft/libft.a ${MLX}

all:		${NAME}

clean:
			${RM} ${OBJS}
			@make clean -C libft/
			@make clean -C mlx_linux/

fclean:		clean
			${RM} ${NAME}
			@make fclean -C libft/

re:			fclean all

.PHONY:		all clean fclean re