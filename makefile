# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 14:47:49 by sasano            #+#    #+#              #
#    Updated: 2023/11/29 02:37:56 by sasano           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
SRCS = ./main.c ./check_map.c ./free.c ./error.c ./game.c ./player.c ./game_utils.c ./check_playable.c
GNL_SRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o) $(GNL_SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -fno-omit-frame-pointer
CC = cc


# Contains the X11 and MLX header files
INCLUDES = -I/opt/X11/include -Imlx

MLX_DIR = ./mlx
# MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
MLX_LIB = $(MLX_DIR)/libmlx_test.a

# Link X11 and MLX, and use OpenGL and AppKit
MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# GET_NEXT_LINE_DIR = ./get_next_line
# GET_NEXT_LINE_LIB = $(GET_NEXT_LINE_DIR)
 
all: $(MLX_LIB) $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_LIB)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@  $(INCLUDES)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)



clean:
		rm -f $(OBJS) $(BOJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re 


