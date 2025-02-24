CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRC = main.c libmlx_Linux.a error.c map_validator.c get_next_line.c\
		get_next_line_utils.c libft/libft.a free_map.c\
		elements_validator.c game_starter.c

NAME = so_long

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(MLX_FLAGS) $(CCFLAGS) $^ -o $@

libft/libft.a:
	make -C libft

clean:
	make clean -C libft

fclean:
	make fclean -C libft
	rm -f so_long

easy: fclean all
	make clean -C libft
	clear

re: fclean all

.PHONEY: all clean fclean easy re
