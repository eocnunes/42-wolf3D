# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/01 13:43:14 by enunes            #+#    #+#              #
#    Updated: 2017/11/01 14:00:57 by enunes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CFLAGS = -Wall -Wextra -Werror -g

SRC_FILES = wolf3d.c \
			parser.c \
			hook.c \
			draw.c \
			ray_casting.c \
			move.c \
			texture.c\
			tools.c \
 
OBJ_FILES = $(SRC_FILES:.c=.o)

SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
MLX_DIR = ./mlx/
LIBFT_DIR = ./libft/

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
MLX = $(addprefix $(MLX_DIR), libmlx.a)
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

LINK = -L $(MLX_DIR) -L $(LIBFT_DIR) \
				-lmlx -lft -framework OpenGL -framework AppKit

all: obj $(LIBFT) $(MLX) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(CFLAGS) -I $(MLX_DIR) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
	@echo -n ████████

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "\033[1;32m> libft created\033[0m"

$(MLX):
	@make -C $(MLX_DIR)
	@echo "\033[1;32m> mlx created\033[0m"
	@echo "\033[32mCompiling..."

$(NAME): $(OBJ)
	@gcc $(CFLAGS) $(OBJ) $(LINK) -lm -o $(NAME)
	@echo "\033[1;32m\n> $(NAME) created\033[0m"

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo "\033[31m> objs removed\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "\033[1;91m> $(NAME) removed\033[0m"

re: fclean all

.PHONY: clean fclean all re
