#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bharmund <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/18 14:49:48 by bharmund          #+#    #+#              #
#    Updated: 2019/07/18 16:21:34 by bharmund         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = fdf
CC = cc -Wall -Wextra -Werror
SRC_LIST = main.c\
			fdf.c\
			read.c\
			draw.c\
			hook.c\
			matrix.c\
			tools.c \
			projection.c
SRC_DIR = srcs/
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))
INCLUDES = -I ./includes/\
			-I ./libft/includes\
			-I ./minilibx_macos/
OBJ_LIST = $(SRC_LIST:.c=.o)
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

LIB = libft/libft.a\
	minilibx_macos/mlx.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ_DIR) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(INCLUDES) -L ./libft/ -lft -L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

$(LIB):
	make -C ./minilibx_macos
	make -C ./libft

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c ./includes/fdf.h
	$(CC) -c $< $(INCLUDES)  -o $@ 

clean:
	make -C ./minilibx_macos clean
	make -C ./libft fclean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C ./minilibx_macos fclean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all