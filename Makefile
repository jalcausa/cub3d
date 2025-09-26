# ANSI color codes
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

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
	src/render/raycast_utils.c \
	src/utils/controls.c \
	src/utils/handle_errors.c \
	src/utils/images.c \
	src/utils/clean.c \
	src/init.c

OBJ_DIR		= Objects
OBJS		= $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

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

$(OBJ_DIR)/%.o: src/%.c
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} ${CPPFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make -s -C libft
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@${CC} ${OBJS} ${LIBS} ${LDFLAGS} -o ${NAME}
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@${RM} -r ${OBJ_DIR}
	@make clean -C ./libft
	@echo "$(GREEN)✓ Object files cleaned$(RESET)"

fclean:	clean
	@echo "$(RED)Removing executable...$(RESET)"
	@${RM} ${NAME}
	@${RM} ./libft/libft.a
	@echo "$(GREEN)✓ Full clean completed$(RESET)"

re: 
	@echo "$(YELLOW)Rebuilding $(NAME)...$(RESET)"
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
