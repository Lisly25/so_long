# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 11:59:07 by skorbai           #+#    #+#              #
#    Updated: 2024/01/02 09:13:33 by skorbai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FLAGS = -Wall -Wextra -Werror

SRCS = check_for_walls.c \
		display_move_count.c \
		draw_map.c \
		exit_game.c \
		main.c \
		map_checker_all.c \
		map_checker_path.c \
		map_checker_symbols.c \
		map_checker_walls.c \
		map_reader.c \
		vector.c \
		window_open.c \

OBJS = $(SRCS:.c=.o)

MLX = mlx/libmlx42.a

MLX_HEADER = mlx/MLX42.h

LIBFT = libft/libft.a

NAME = CatGame

all: $(NAME)

$(LIBFT) :
	make -C ./libft

$(NAME) : $(OBJS) $(MLX) $(LIBFT)
	cc $(OBJS) $(MLX) $(LIBFT) -ldl -pthread -lm -L/Users/skorbai/.brew/Cellar/glfw/3.3.8/lib -lglfw -I $(MLX_HEADER) -o $(NAME)

%.o: %.c 
	cc $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C ./libft

fclean: clean 
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re