#include "cub.h"

int split_len(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
static int	ft_isspace(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		res;
	size_t	i;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		return ((char *)s + i);
	}
	return (NULL);
}
int is_line_empty(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\n' && *line != '\r')
			return 0;
		line++;
	}
	return 1;
}
