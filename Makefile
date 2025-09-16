NAME		= cub3D

SRCS		=	src/main.c				\
				src/render/player.c		\
				src/render/paint.c		\
				src/render/raycast.c	\
				src/utils/controls.c	\
				src/utils/images.c

OBJS		= ${SRCS:.c=.o}

CC			= cc

LIBS		= ./MLX42/build/libmlx42.a ./libft/libft.a -lglfw -lm -ldl -pthread

#Linker flags
LDFLAGS		= -L/opt/homebrew/lib -L/usr/local/lib

# C PreProcessor Flags
CPPFLAGS	= -I/opt/homebrew/include -I/usr/local/include -I./MLX42/include -I./libft -I ./inc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

all: ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} ${CPPFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@make -s -C libft
	@${CC} ${OBJS} ${LIBS} ${LDFLAGS} -o ${NAME}
	@echo "cub3d compiled"

clean:
	@${RM} ${OBJS}
	@make clean -C ./libft

fclean:	clean
	@${RM} ${NAME}
	@rm -rf $.libft/libft.a

re: fclean all

.PHONY: all clean fclean re

re: fclean all

.PHONY: all clean fclean re
