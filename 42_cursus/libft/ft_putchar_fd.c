#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c , 1);
}

// #include<stdio.h>
// #include<fcntl.h>
// int main()
// {
// 	int fd;

// 	fd = open("emma.txt",O_CREAT | O_WRONLY);
// 	ft_putchar_fd('a', fd);
// 	printf("%d\n",fd);
// 	close(fd);
// }