NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = dup_checker.c ft_atoi.c ft_lstclear.c ft_split.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
		limit_checker.c ft_isdigit.c ft_lstadd_back.c\
		ft_lstlast.c ft_lstnew.c ft_strlen.c lst_before_last.c\
		lst_largest.c ft_lstadd_front.c ft_lstsize.c lst_smallest.c
		ft_charcmp.c

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

.PHONY: all clean fclean re

.SECONDARY:
