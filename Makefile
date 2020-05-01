# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erahimi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 11:38:24 by erahimi           #+#    #+#              #
#    Updated: 2020/02/23 22:54:42 by ibel-kha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRCS = init.c\
	   main.c\
	   vector1.c\
	   vector2.c\
	   vector3.c\
	   draw_calcul.c\
	   plane.c\
	   cylinder.c\
	   cone.c\
	   sphere.c\
	   parser.c\
	   color.c\
	   tools.c\
	   closer.c\
	   load_texture.c\
		texture.c\
		voronoi.c\
		rand.c\
		perlin.c\
		get_color.c\
		mb_filter.c\
		filtres.c\
		sepia_filtre.c\
		repere.c\
		projection.c\
		add_component.c\
		disk.c\
		slice.c
		
OBJS = $(SRCS:.c=.o)

SRC = $(SRCS:%=srcs/%)

OBJ = $(OBJS:%=objs/%)

OBJ_DIR = objs

LIBFT = -L libft -lft

CFLAGS = -Wall -Wextra #-Werror

CC = gcc $(CFLAGS)

#MLX = -lmlx -framework OpenGL -framework AppKit

ifeq ($(shell uname), Darwin)
MLX_DIR = minilibx_macos
MLX = -lmlx -framework OpenGL -framework AppKit
else
MLX_DIR = minilibx_linux
MLX = -lm -lmlx -lXext -lX11 -lbsd
endif

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	make -C libft libft.a
	make -C $(MLX_DIR)
	@$(CC) -o $@ $(OBJ) -L $(MLX_DIR) $(MLX) -I $(MLX_DIR) $(LIBFT) $(MLX) -I .

$(OBJ_DIR):
	@mkdir -p $@

objs/%.o: srcs/%.c
	$(CC) -c $< -o $@ -I .

.PHONY: clean
clean:
	@make clean -C libft/
	@rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

.PHONY: re
re: fclean all
