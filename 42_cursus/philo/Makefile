CC = cc

CFLAGS = -Wall -Wextra -Werror
NAME = philo

FILES = main.c init.c dinner.c one_philo.c parcing.c utils.c supervisor.c actions.c\

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