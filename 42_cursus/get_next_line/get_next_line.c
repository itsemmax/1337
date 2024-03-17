/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:53:14 by ichaoub           #+#    #+#             */
/*   Updated: 2024/03/17 15:53:21 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *left, int fd)
{
	char	*line;
	int		n;

	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	n = 1;
	while (!ft_strchr(left, '\n') && n != 0)
	{
		n = read(fd, line, BUFFER_SIZE);
		if (n == -1)
		{
			free(left);
			free(line);
			return (NULL);
		}
		line[n] = '\0';
		left = ft_strjoin(left, line);
	}
	free(line);
	return (left);
}

char	*ft_get_line(char *left)
{
	char	*tmp;
	int		i;

	i = 0;
	while (!left || left[i] == '\0')
		return (NULL);
	while (left[i] && left[i] != '\n')
		i++;
	tmp = (char *)malloc((i + 2) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (left[i] && left[i] != '\n')
	{
		tmp[i] = left[i];
		i++;
	}
	if (left[i] == '\n')
	{
		tmp[i] = left[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*new_left(char *left)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (left[i] && left[i] != '\n')
		i++;
	if (left[i] == '\0')
	{
		free(left);
		return (NULL);
	}
	new = (char *)malloc(((ft_strlen(left) - i) + 1) * sizeof(char));
	if (!new)
	{
		free(left);
		return (NULL);
	}
	i++;
	j = 0;
	while (left[i])
		new[j++] = left[i++];
	new[j] = '\0';
	free(left);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	left = read_line(left, fd);
	if (!left)
		return (NULL);
	str = ft_get_line(left);
	left = new_left(left);
	return (str);
}

// #include <stdio.h>
// int main(void)
// {
// 	int fd;
// 	char *str;
// 	fd = open("emma.txt",O_RDONLY);
// 	while((str = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s",str);
// 		free(str);
// 	}
// 	printf("%s",str);
// 	close(fd);
// 	return(0);
// }
// #include<stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("emma.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("Line read: %s\n", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
// #include<stdio.h>
// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("emma.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("Ligne lue : %s\n", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
// int		main(int ac, char **av)
// {
// 	char	*line;
// 	int		fd1;

// 	fd1 = open("emma.txt", O_RDONLY);
// 	get_next_line(fd1);
// 	return (0);
// }
