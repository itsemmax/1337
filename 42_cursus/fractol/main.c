#include"fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (NULL == s1 || NULL == s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}

int	main(int argc,char **argv)
{
	t_fractal fractal;
	if((argc == 2 && !ft_strncmp(argv[1],"mandelbrot",10))
		|| (argc == 4 && !ft_strncmp(argv[1],"julia",5))
		|| (argc == 2 && !ft_strncmp(argv[1],"julia",5)))
	{
		fractal.name = argv[1];
		get_value(argc, argv, &fractal);
		data_init(&fractal);
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		write(2, "Error: wrong format. Try: ./fractol mandelbrot\n or ./fractol julia\n or ./fractol julia <x> <y>\n", 96);
		exit(EXIT_FAILURE);
	}
}