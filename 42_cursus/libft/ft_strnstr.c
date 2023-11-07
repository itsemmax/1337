#include"libft.h"

char *ft_strnstr(const char *haystack,const char *needle,size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if(!needle)
	{(
		return((char *)haystack));
	}
	while(haystack[i] && i < len)
	{
		j = 0;
		while((i + j )< len && haystack[i+j] == needle[j])
		{
			j++;
		}
		if(needle[j] =='\0')
		{
			return((char *)&haystack[i]);
		}
		i++;
	}
	return(NULL);
}
#include<stdio.h>
#include<string.h>
int main()
{
const char tab[] = "hello imane zweena";
const char tab1[] = "imane";
printf("%s",ft_strnstr(tab,tab1,16));
//printf("%s",strnstr(tab,tab1,16));
}