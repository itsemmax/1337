#include "cub.h"

static int	count_word(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static void	ft_strncpy(char *dst, char *src, int c)
{
	int	i;

	i = 0;
	while (src[i] && i < c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static void	*ft_free(char **p, int a)
{
	int	i;

	i = 0;
	while (i < a)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

static void	*rempli(char *s, char c, char **p, int count)
{
	int	j;
	int	i;

	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		j = 0;
		while (*s != c && *s)
		{
			s++;
			j++;
		}
		p[i] = (char *)malloc(sizeof(char) * (j + 1));
		if (!p[i])
			return (ft_free(p, i));
		ft_strncpy(p[i], (char *)(s - j), j);
		i++;
	}
	p[i] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**p;

	if (!s)
		return (NULL);
	count = count_word((char *)s, c);
	p = (char **)malloc(sizeof(char *) * (count + 1));
	if (!p)
		return (NULL);
	return (rempli((char *)s, c, p, count));
}