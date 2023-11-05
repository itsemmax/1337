#include"libft.h"
#include <string.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *a;
	unsigned char *b;
	

	a = (unsigned char *) dest;
	b = (unsigned char *) src;
	if(a > b)
	{
		while(n > 0)
		{
			a[n-1] = b[n-1];
			n--;
		}
	}
	else
	{
		ft_memcpy(a,b,n);
	}
	return (dest);
}
/*#include <stdio.h>
int main(){
	char p[8]= "WAHIBAB";
	ft_memmove(p+2, p+2, 3);
	printf("%s", p);
}*/