#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int i;

	i = 0;
	while(s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*#include<stdio.h>

void test(unsigned int a, char *b)
{
	printf("s[%i] = %c\n",a,*b);
}

int main()
{
	ft_striteri("hello",&test);
}*/

