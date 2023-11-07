
#include "libft.h"

size_t ft_strlen(const char *s)
{
	size_t i;


	i = 0;
	while(s && s[i])
	{
		i++;
	}
	return (i);
}
/*int main ()
{
	char *str = NULL;
	printf("%ld", ft_strlen(str));
}*/