CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Zombie

SRCS = main.cpp Zombie.cpp zombieHorde.cpp\

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJ)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re