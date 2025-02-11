CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c error.c map_validator.c get_next_line.c\
		get_next_line_utils.c libft/libft.a
NAME = so_long

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CCFLAGS) $^ -o $@

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
