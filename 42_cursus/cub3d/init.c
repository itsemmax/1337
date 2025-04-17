#include "cub.h"

void init(t_info *map)
{
	map->no_texture = NULL;
	map->we_texture = NULL;
	map->ea_texture = NULL;
	map->so_texture = NULL;
	map->floor_color = -1;
	map->ceiling_color = -1;
	map->map_width = 0;
	map->map_height = 0;
	map->map = NULL;
	map->player_x = 0;
	map->player_y = 0;
	map->player_dir = 0;
	map->mini_pos_x = 0;
	map->mini_pos_y = 0;
	map->speed = 0;
}
int init_ea_texture(t_info *map)
{
	map->ea_texture = malloc(sizeof(t_texture));
	if (!map->ea_texture)
	{
		free(map->no_texture);
		free(map->so_texture);
		free(map->we_texture);
		return (printf("Error: malloc failed\n"), 1);
	}
	map->ea_texture->is_init = 0;
	return (0);
}
int init_map(t_info *map)
{
	map->no_texture = malloc(sizeof(t_texture));
	if (!map->no_texture)
		return (printf("Error: malloc failed\n"), 0);
	map->no_texture->is_init = 0;
	map->so_texture = malloc(sizeof(t_texture));
	if (!map->so_texture)
	{
		free(map->no_texture);
		return (printf("Error: malloc failed\n"), 0);
	}
	map->so_texture->is_init = 0;
	map->we_texture = malloc(sizeof(t_texture));
	if (!map->we_texture)
	{
		free(map->no_texture);
		free(map->so_texture);
		return (printf("Error: malloc failed\n"), 0);
	}
	map->we_texture->is_init = 0;
	if(init_ea_texture(map))
		return(0);
	return(1);
}
