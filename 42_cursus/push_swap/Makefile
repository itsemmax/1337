CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
NAME = push_swap

FILES = push_swap.c ft_lst.c ft_Split.c push.c reverse_rotate.c big_sort.c\
        rotate.c sort_utils.c sort.c swap.c tab.c utils.c utils1.c free.c \

OBJ = $(FILES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
