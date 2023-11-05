#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;
	size_t i;

	i = 0;
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if(!d && !s)
	{
		return(0);
	}
	while(d[i] && i < n)
	{
		d[i] = s[i];
		i++;
	}
	return(dest);

}
/*#include<stdio.h>

int main(){
	char s[] = "hello";
	char t[] = "imanech";
	char a[] = "hello";
	char b[] = "imanech";
	(char *)ft_memcpy(s,t,7);
	(char *)memcpy(a,b,7);
	printf("%s\n",s);
	printf("%s\n",a);
}*/