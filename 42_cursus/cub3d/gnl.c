#include "cub.h"

char *ft_strdup(char *s1)
{
	size_t len = ft_strlen(s1);
	char *copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	for (size_t i = 0; i < len; i++)
		copy[i] = s1[i];
	copy[len] = '\0';
	return (copy);
}

char *get_next_line(int fd)
{
	char buf;
	char *line = malloc(1);
	int len = 0;
	int read_ret;

	if (!line)
		return (NULL);
	line[0] = '\0';

	while ((read_ret = read(fd, &buf, 1)) == 1)
	{
		char *tmp = malloc(len + 2);
		if (!tmp)
			return (free(line), NULL);
		for (int i = 0; i < len; i++)
			tmp[i] = line[i];
		tmp[len++] = buf;
		tmp[len] = '\0';
		free(line);
		line = tmp;
		if (buf == '\n')
			break;
	}
	if (read_ret <= 0 && len == 0)
		return (free(line), NULL);
	return (line);
}

// char	*ft_strdup(char *s1)
// {
// 	char	*copy;
// 	size_t	s1_len;
// 	int		i;

// 	i = 0;
// 	s1_len = ft_strlen(s1);
// 	copy = malloc(sizeof(char) * (s1_len + 1));
// 	if (!copy)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		copy[i] = s1[i];
// 		i++;
// 	}
// 	copy[i] = '\0';
// 	return (copy);
// }

// char	*get_next_line(int fd)
// {
// 	char	line[8000000];
// 	char	buf;
// 	int		i;

// 	i = 0;
// 	while (read(fd, &buf, 1) == 1)
// 	{
// 		line[i++] = buf;
// 		if (buf == '\n')
// 			break ;
// 	}
// 	line[i] = '\0';
// 	if (!line[0])
// 		return (NULL);
// 	return (ft_strdup(line));
// }
