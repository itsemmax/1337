# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 10:32:37 by ichaoub           #+#    #+#              #
#    Updated: 2023/11/13 10:50:27 by ichaoub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -std=c99

DEPS = libft.h

OBJ = ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o\
ft_memset.o ft_strchr.o ft_strlen.o ft_strncmp.o ft_strrchr.o ft_toupper.o ft_tolower.o\
ft_memchr.o ft_bzero.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o\
ft_strnstr.o ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o\





%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJBONUS) $(NAME) $(OBJ)
	ar rcs $(NAME) $(OBJBONUS) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all