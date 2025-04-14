#include "cub.h"

int	check_extension(char *str)
{
	int i;

	i = ft_strlen(str);
	if(str[i - 1] != 'b' || str[i - 2] != 'u' 
		|| str[i - 3] != 'c' || str[i - 4] != '.')
		return(1);
	return(0);
}
int main(int argc, char **argv)
{
	t_info map;

	if (argc != 2)
		return (printf("Error: invalid number of args\n"), 1);
	if (check_extension(argv[1]) == 1)
		return (printf("Error: invalid map extension\n"), 1);

	init(&map);

	map.mlx = mlx_init();
	if (!map.mlx)
		return (printf("Error: failed to initialize mlx\n"), 1);
	if (!parse_map(&map, argv[1]))
	{
		printf("Error: failed to parse\n");
		mlx_destroy_display(map.mlx);
		free(map.mlx);
		return (1);
	}
	map.win = mlx_new_window(map.mlx, WIDTH, HEIGHT, "cub3d");
	if (!map.win)
	{
		mlx_destroy_display(map.mlx);
		free(map.mlx);
		return (printf("Error: failed to create window\n"), 1);
	}
	mlx_loop(map.mlx);
	return (0);
}
