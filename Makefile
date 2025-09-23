NAME		= cub3D

SRCS = src/main.c \
	src/parser/check_colour.c \
	src/parser/check_map.c \
	src/parser/check_scene.c \
	src/parser/check_wall.c \
	src/parser/get_map.c \
	src/parser/parse.c \
	src/parser/read_map.c \
	src/parser/read_scene.c \
	src/render/paint.c \
	src/render/player.c \
	src/render/raycast.c \
	src/utils/controls.c \
	src/utils/handle_errors.c \
	src/utils/images.c

OBJS		= ${SRCS:.c=.o}

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

# Detect OS (Darwin = macOS)
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	LIBS = ./MLX42/build/libmlx42.a ./libft/libft.a -lglfw -lm -pthread
	LDFLAGS = -L/opt/homebrew/lib -L/usr/local/lib
	CPPFLAGS = -I/opt/homebrew/include -I/usr/local/include -I./MLX42/include -I./libft -I./inc
else
	LIBS = ./MLX42/build/libmlx42.a ./libft/libft.a -lglfw -lm -ldl -pthread
	LDFLAGS =
	CPPFLAGS = -I./MLX42/include -I./libft -I./inc
endif

all: ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} ${CPPFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@make -s -C libft
	@${CC} ${OBJS} ${LIBS} ${LDFLAGS} -o ${NAME}
	@echo "cub3D compiled"

clean:
	@${RM} ${OBJS}
	@make clean -C ./libft

fclean:	clean
	@${RM} ${NAME}
	@${RM} ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re
