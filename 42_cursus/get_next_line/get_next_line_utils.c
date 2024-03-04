#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while(s[i])
	{
		i++;
	}
	return(i)
}
// #include<stdio.h>
// int main()
// {
// 	char tab[] = "hello";
// 	printf("%i\n",ft_strlen(tab));
// }