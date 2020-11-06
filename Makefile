# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 15:27:55 by k3                #+#    #+#              #
#    Updated: 2020/11/05 08:05:06 by k3               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBR = -L$(LIB_DIR) -lft -lm
MLXLIBR = -lmlx -framework OpenGL -framework AppKit -L$(MLX_DIR)
INCL = -I$(HDR_DIR) -I$(LIB_DIR) -I$(MLX_DIR)

LIB = $(LIB_DIR)libft.a
LIB_DIR = ./libft/
LIB_HDR = $(LIB_DIR)libft.h

MLX = $(MLX_DIR)libmlx.a
MLX_DIR = ./mlx/
MLX_HDR = $(MLX_DIR)mlx.h

HDR_DIR = ./include/
HDR_LIST = fdf.h
HDR = $(addprefix $(HDR_DIR), $(HDR_LIST))

SRC_DIR = ./src/
SRC_LIST = 	main.c read_map.c init_fdf.c keyboard.c image.c mods.c rotate_frame.c\
	points.c draw.c helper.c moving.c rotate_point.c coords.c
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = ./obj/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB) $(MLX) $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(LIBR) $(MLXLIBR) -o $(NAME)
	@echo $@ Done

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo OBJECT_DIRECTORY is created

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDR)
	@$(CC) $(FLAGS) $(INCL) -o $@ -c $<
	@echo OBJECT: $@ updated

$(LIB):
	@$(MAKE) -C $(LIB_DIR)
	@echo libft Done

$(MLX):
	@$(MAKE) -C $(MLX_DIR)
	@echo mlx Done

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo clean Done

fclean:
	@$(MAKE) clean
	@rm -f $(LIB)
	@rm -f $(NAME)
	@echo fclean Done

re:
	@$(MAKE) fclean
	@$(MAKE) all
