#include "cub.h"

int free_array(char ***str, int a)
{
	int i;

	if(*str == NULL)
		return (0);
	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		i++;
	}
	free(*str);
	if(a)
		return(printf("invalid character in map\n"), -1);
	return (0);
}
int free_texture(t_info *map)
{
	if (map->no_texture->is_init)
		mlx_destroy_image(map->mlx, map->no_texture->img);
	if (map->so_texture->is_init)
		mlx_destroy_image(map->mlx, map->so_texture->img);
	if (map->ea_texture->is_init)
		mlx_destroy_image(map->mlx, map->ea_texture->img);
	if (map->we_texture->is_init)
		mlx_destroy_image(map->mlx, map->we_texture->img);
	free(map->no_texture);
	free(map->so_texture);
	free(map->ea_texture);
	free(map->we_texture);
	return (0);
}
