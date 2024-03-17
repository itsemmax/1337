#include "get_next_line.h"

char	*read_line(char *left, int fd)
{
	char	*str;
	int		n;

	str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	n = 1;
	while (!ft_strchr(left, '\n') && n != 0)
	{
		n = read(fd, str, BUFFER_SIZE);
		if (n == -1)
		{
			free(str);
			free(left);
			return (NULL);
		}
		str[n] = '\0';
		left = ft_strjoin(left, str);
	}
	free(str);
	return (left);
}
char	*ft_get_line(char *left)
{
	char	*str;
	int		i;

	i = 0;
	if (!left || !left[i])
		return (NULL);
	while (left[i] && left[i] != '\n')
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (left[i] && left[i] != '\n')
	{
		str[i] = left[i];
		i++;
	}
	if (left[i] == '\n')
	{
		str[i] = left[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
char	*new_left(char *left)
{
	char	*str;
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
	str = (char *)malloc((ft_strlen(left) - i + 1) * sizeof(char));
	if (!str)
	{
		free(left);
		return (NULL);
	}
	i++;
	j = 0;
	while (left[i])
	{
		str[j++] = left[i++];
	}
	str[j] = '\0';
	free(left);
	return (str);
}
char	*get_next_line(int fd)
{
	static char *left[1024] = {NULL};
	char *str;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	left[fd] = read_line(left[fd], fd);
	if (!left[fd])
		return (NULL);
	str = ft_get_line(left[fd]);
	left[fd] = new_left(left[fd]);
	return (str);
}
// #include<stdio.h>
// int main(void)
// {
// 	int fd0;
// 	int fd1;
// 	char *str;
// 	char *str2;
// 	int i = 0;

// 	fd0 = open("imane.txt",O_RDONLY);
// 	fd1 = open("emma.txt", O_RDONLY);
// 	str = get_next_line(fd0);
// 	printf("%s",str);
// 	free(str);
// 	str2 = get_next_line(fd1);
// 	printf("%s",str2);
// 	free(str2);
// 	str = get_next_line(fd0);
// 	printf("%s",str);
// 	free(str);
// 	str2 = get_next_line(fd1);
// 	printf("%s",str2);
// 	free(str2);
// 	return(0);
// }