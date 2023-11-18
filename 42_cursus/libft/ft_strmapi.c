#include"libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int i;
	char *str;

	i = 0;
	str = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));
	if(!str)
	{
		return(NULL);
	}
	while(s[i])
	{
		str[i] = f(i,s[i]);
		i++;
	}
	str[i] = '\0';
	return(str);
}

/*#include<stdio.h>

char test_fct(unsigned int a, char b)
{
	printf("index %u---------char %c\n",a,b);
	return(0);
}

int main()
{
	char *result;
	result = ft_strmapi("hello",&test_fct);
	printf("%s",result);
}*/