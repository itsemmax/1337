#include"libft.h"

char *ft_substr(char const *s, unsigned int start,size_t len)
{
	char *p;
	size_t i;

	i = 0;
	if(!s)
	{
		return(NULL);
	}
	if(start >= ft_strlen(s))
	{
		ft_strdup("");
	}
	if(ft_strlen(s) < start + len)
	{
		p = malloc((ft_strlen(s) - start) + 1);
	}
	else
		p = malloc(len + 1);
	if(!p)
	{
		return(NULL);
	}
	while(i < len)
	{
		p[i] = s[start - 1];
		i++;
		start++;
	}
	p[i] = '\0';
	return(p);
}

/*#include<stdio.h>

int main()
{
	char *p;
	p =ft_substr("hello world",7,18);
	printf("%s",p);
	free(p);
}*/