CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = mlx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

NAME = cub3D
SRCS = main.c \
		colors.c ft_split.c parse.c free.c gnl.c init.c \
		textures.c utils.c utils1.c map.c utils2.c map1.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
