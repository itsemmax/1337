#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return(i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (NULL);
	while (i < (int)ft_strlen(s1))
	{
		p[i] = s1[i];
		i++;
	}
	while (j < (int)ft_strlen(s2))
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = '\0';
	return (p);
}
