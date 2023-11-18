#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

// #include<stdio.h>
// #include<fcntl.h>

// int main()
// {
// 	int fd;

// 	fd = open("samira.txt", O_CREAT | O_WRONLY);
// 	ft_putendl_fd("hello world", fd);
// 	printf("%d", fd);
// 	close(fd);
// }