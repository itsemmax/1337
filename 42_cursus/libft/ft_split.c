#include "libft.h"


char check_sep(char a, char c)
{
	if(a == c)
		return(1);
	return(0);
}

int count_word(char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(s[i])
	{
		while(check_sep(s[i],c))
			i++;
		if(s[i])
			count++;
		while(!check_sep(s[i], c) && s[i] )
		i++;
	}
	return(count);

}
void	ft_strncpy(char *dst, char *src,int c)
{
	int i;

	i = 0;
	while(src[i] && i < c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}
void ft_free(char  **p , int a)
{
	int i;

	i = 0;
	while(i < a)
	{
		free(p[i]);
		i++;
	}
	free(p);
}

char **ft_split(char const *s, char c){
	int i;
	int j;
	char **p;
	int count = count_word((char *)s, c);

	i = 0;
	p = (char **)malloc(sizeof (char *) * (count + 1));
	if(!p)
	{
		return(NULL);
	}
	while(i < count)
	{
		while(check_sep(*s, c))
			s++;
		j = 0;
		while(!check_sep(*s,c) && *s)
		{
			s++;
			j++;
		}
		p[i] = (char *)malloc(sizeof(char) * (j + 1));
		if(!p[i])
		{
			ft_free(p , i);
		}
		ft_strncpy(p[i],(char *)s - j, j);
		i++;
	}
	p[i] = NULL;
	return(p);
}

/*#include <stdio.h>
int main()
{
	int i = 0;

	char *p = " hello       world      imane ";
	char c = ' ';
	char **a = ft_split(p,c);
	while(i < 3)
	{
		printf("%s",a[i]);
		printf("\n");
		i++;
	}
	free(a);
}*/