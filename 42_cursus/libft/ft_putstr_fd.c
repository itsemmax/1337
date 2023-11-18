#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	while(s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

// #include<stdio.h>
// #include<fcntl.h>

// int main()
// {
// 	int fd;

// 	fd = open("test.txt",O_CREAT | O_WRONLY);
// 	ft_putstr_fd("hello imane" , fd);
// 	printf("%d", fd);
// 	close(fd);
// }