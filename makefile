# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 14:47:49 by sasano            #+#    #+#              #
#    Updated: 2024/11/14 15:45:13 by sasano           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = ./main.c ./check_map.c ./free.c ./error.c ./game.c ./player.c ./game_utils.c ./check_playable.c
GNL_SRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o) $(GNL_SRCS:.c=.o)
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -fno-omit-frame-pointer
CFLAGS = -Wall -Wextra -Werror
CC = cc
OS = $(shell uname)
# MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib
MLX_FLAGS = -Lmlx -lmlx

ifeq ($(OS), Linux)
	MLX_FLAGS += -L/usr/X11/lib -lXext -lX11
	INCLUDES = -I/usr/include -Imlx
	CFLAGS += -D__Linux__
else ifeq ($(OS), Darwin)
	MLX_FLAGS += -framework OpenGL -framework AppKit
	INCLUDES = -I/opt/X11/include -Imlx
	CFLAGS += -D__Apple__
endif


# Contains the X11 and MLX header files
# INCLUDES = -I/opt/X11/include -Imlx

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx.a

# Link X11 and MLX, and use OpenGL and AppKit
# MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit


LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

# GET_NEXT_LINE_DIR = ./get_next_line
# GET_NEXT_LINE_LIB = $(GET_NEXT_LINE_DIR)
 
all: $(MLX_LIB) $(LIBFT_LIB) $(FT_PRINTF_LIB) $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(FT_PRINTF_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_LIB) $(FT_PRINTF_LIB)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@  $(INCLUDES)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)
	
$(FT_PRINTF_LIB):
	@make -C $(FT_PRINTF_DIR)

clean:
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean
	rm -f $(OBJS) $(BOJS)

fclean:	clean
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re 


