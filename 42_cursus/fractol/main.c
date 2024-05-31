#include"fractol.h"

static	int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((!s1 && !s2) || !n)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char) s2[i]);
}

static int ft_isdigit(char *str)
{
	int i;

	i = 0;
	if(str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	else
		return(0);
	return(1);
}
void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
int	main(int argc,char **argv)
{
	if((argc == 2 && !strncmp(argv[1],"mandelbrot",10))
		|| (argc == 4 && !strncmp(argv[1],"julia",5)
		&& ft_isdigit(argv[2]) && ft_isdigit(argv[3]))
		|| (argc == 4 && !strncmp(argv[1],"julia",5)))
	else
	{
		putstr("")
	}
}