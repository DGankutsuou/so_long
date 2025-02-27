CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm

SRC = main.c error.c map_validator.c get_next_line.c\
		get_next_line_utils.c libft/libft.a free_map.c\
		elements_validator.c game_starter.c distroyer.c\
		init.c moves.c libft/ft_putnbr_fd.c animations.c\
		draw.c

NAME = so_long

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $^ $(MLX_FLAGS) -o $@

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
