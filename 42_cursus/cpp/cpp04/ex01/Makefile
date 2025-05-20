CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Animal

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp brain.cpp\

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