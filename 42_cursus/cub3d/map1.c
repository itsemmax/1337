#include "cub.h"

double  get_ort(char c)
{
	if (c == 'E')
		return (0.0);
	else if (c == 'W')
		return (M_PI);
	else if (c == 'N')
		return (3 * M_PI_2);
	else if (c == 'S')
		return (M_PI_2);
	return(3 * M_PI_2);
}

void set_player_start_position(t_info *map)
{
	int a;
	int b;

	a = 0;
	while(map->map[a])
	{
		b = 0;
		while(map->map[a][b])
		{
			if (map->map[a][b] == 'W' || map->map[a][b] == 'E' || \
				map->map[a][b] == 'S' || map->map[a][b] == 'N')
			{
				map->player_x = b * CUBE_SIZE + CUBE_SIZE / 2;
				map->player_y = a * CUBE_SIZE + CUBE_SIZE / 2;
				map->mini_pos_x = b * MINI_MAP_SIZE + MINI_MAP_SIZE /2;
				map->mini_pos_y = a * MINI_MAP_SIZE + MINI_MAP_SIZE /2;
				map->speed = SPEED;
				map->player_dir = get_ort(map->map[a][b]);
				return;
			}
			b++;
		}
		a++;
	}
}