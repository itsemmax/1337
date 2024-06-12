#include"fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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

int	main(int argc,char **argv)
{
	t_fractal fractal;
	if((argc == 2 && !ft_strncmp(argv[1],"mandelbrot",10))
		|| (argc == 4 && !ft_strncmp(argv[1],"julia",5))
		|| (argc == 2 && !ft_strncmp(argv[1],"julia",5)))
	{
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