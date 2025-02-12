NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_split.c ft_putchar_fd.c ft_putstr_fd.c\
		ft_putendl_fd.c ft_strlen.c ft_strncmp.c\
		ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
		sherror.c error.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^

clean:
	rm -f $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

fclean: clean
	rm -f $(NAME)

re: fclean all

easy: all clean
	clear

.PHONY: all clean fclean re

.SECONDARY:
