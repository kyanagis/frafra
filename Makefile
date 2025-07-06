# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/05 04:36:45 by kyanagis          #+#    #+#              #
#    Updated: 2025/07/05 04:36:54 by kyanagis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := fractol
CC          := cc
MATH_OPT    := -Ofast -ffast-math
CFLAGS      := -Wall -Wextra -Werror $(MATH_OPT) -Iinclude -Iminilibx-linux -Ilibft -Ift_printf
LDFLAGS     := -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz \
               -Llibft -lft -Lft_printf -lftprintf

SRC_DIR     := src
OBJ_DIR     := obj

SRC         := $(SRC_DIR)/main.c              \
               $(SRC_DIR)/init.c              \
               $(SRC_DIR)/render.c            \
               $(SRC_DIR)/hooks.c             \
               $(SRC_DIR)/color.c             \
               $(SRC_DIR)/mandelbrot.c        \
               $(SRC_DIR)/julia.c             \
               $(SRC_DIR)/burning_ship.c      \
               $(SRC_DIR)/sierpinski_gasket.c

OBJ         := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a

PRINTF_DIR  := ft_printf
PRINTF      := $(PRINTF_DIR)/libftprintf.a

MLX_DIR     := minilibx-linux
MLX_LIB     := $(MLX_DIR)/libmlx.a
MLX_GIT     := https://github.com/42Paris/minilibx-linux.git

.PHONY: all clean fclean re $(LIBFT) $(PRINTF)

all: $(MLX_LIB) $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX_LIB):
	@if [ ! -d $(MLX_DIR) ]; then \
		git clone $(MLX_GIT) $(MLX_DIR); \
	fi
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	@if [ -d $(MLX_DIR) ]; then $(MAKE) -C $(MLX_DIR) clean; fi

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all
