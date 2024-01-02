# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 11:59:07 by skorbai           #+#    #+#              #
#    Updated: 2024/01/02 16:48:21 by skorbai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FLAGS = -Wall -Wextra -Werror

SRCS = check_for_walls.c \
		display_move_count.c \
		draw_map.c \
		error.c \
		exit_game.c \
		main.c \
		map_checker_all.c \
		map_checker_path.c \
		map_checker_symbols.c \
		map_checker_walls.c \
		map_reader.c \
		vector.c \
		window_open.c

BONUS_SRCS = check_for_walls_bonus.c \
		display_move_count_bonus.c \
		draw_map_bonus.c \
		error.c \
		exit_game.c \
		main.c \
		map_checker_all.c \
		map_checker_path.c \
		map_checker_symbols.c \
		map_checker_walls.c \
		map_reader.c \
		vector.c \
		window_open.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

MLX = MLX42/build/libmlx42.a

MLX_HEADER = MLX42/include/MLX42/MLX42.h

LIBFT = libft/libft.a

NAME = so_long

all: $(NAME)

$(LIBFT) :
	make -C ./libft

$(MLX) :
	cd MLX42 &&	cmake -B build && cmake --build build -j4

$(NAME) : $(OBJS) $(MLX) $(LIBFT)
	cc $(OBJS) $(MLX) $(LIBFT) -ldl -pthread -lm -L/Users/skorbai/.brew/Cellar/glfw/3.3.8/lib -lglfw -I $(MLX_HEADER) -o $(NAME)

bonus: .bonus

.bonus : $(BONUS_OBJS) $(MLX) $(LIBFT)
	cc $(BONUS_OBJS) $(MLX) $(LIBFT) -ldl -pthread -lm -L/Users/skorbai/.brew/Cellar/glfw/3.3.8/lib -lglfw -I $(MLX_HEADER) -o $(NAME)
	@touch .bonus

%.o: %.c 
	cc $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	@rm -f .bonus
	make clean -C ./libft

fclean: clean 
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re bonus