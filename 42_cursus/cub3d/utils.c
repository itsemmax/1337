#include "cub.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}
int ft_strlenwnl(char *str)
{
	int i;

	i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	return(i);
}
int ft_strncmp(char *s1, char *s2, int n)
{
	int i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return 0;
}

// int ft_strncmp(char *s1, char *s2, int n)
// {
// 	int i;

// 	i = 0;
// 	while(s1[i] && s2[i] && i < n)
// 	{
// 		if(s1[i] != s2[i])
// 			return(0);
// 		i++;
// 	}
// 	return(1);
// }
char *ft_dupwnl(char *str)
{
	char *dup;
	int i;
	int j;

	i = ft_strlenwnl(str);
	if(i == 1 && str[0] == '\n')
		return(ft_strdup(""));
	while(str[i] == '\0' || str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
		i--;
	dup = malloc(sizeof(char) * (i + 2));
	if(!dup)
		return (dup);
	j = 0;
	while(j < i + 1)
	{
		dup[j] = str[j];
		j++;
	}
	dup[j] = '\0';
	return(dup);
}
int is_valid_map(char c)
{
	if(c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return(1);
	return(0);
}