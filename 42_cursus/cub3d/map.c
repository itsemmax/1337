#include "cub.h"

int allocate_map_grid(t_info *map,int height, int width)
{
	int i;

	map->map = malloc(sizeof(char *) * (height + 1));
	if(!map->map)
	{
		free_texture(map);
		return(printf("Error: failed to allocate memory for map\n"), 0);
	}
	map->map[height] = NULL;
	i = 0;
	while(i < height)
	{
		map->map[i] = malloc(sizeof(char) * (width + 1));
		if(!map->map[i])
		{
			free_map(&map->map, i);
			return(printf("Error: failed to allocate memory for map\n"), 0);
		}
		map->map[i][width] = '\0';
		while((i == height - 1) && width > 0)
			map->map[i][--width] = ' ';
		i++;
	}
	return(1);
}

int is_valid_map(char *line)
{
	if (!line || line[0] == '\0' || line[0] == '\n')
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (0);
	else
		return (1);
}
int fill_map(char *line,t_info *map,int i)
{
	int j;

	j = 0;
	while(line[j] != '\n' && line[j] != '\0')
	{
		// if(line[j] == '1' || line[j] == '0' || line[j] == ' '
		// || line[j] == 'S' || line[j] == 'N' || line[j] == 'E' || line[j] == 'W')
		// 	map->map[i][j] = line[j];
		// else
		// 	return (printf("Error: invalid character in map\n"), 0);
		if (line[j] == '1' || line[j] == '0' || line[j] == ' '
			|| line[j] == 'S' || line[j] == 'N' || line[j] == 'E' || line[j] == 'W')
			map->map[i][j] = line[j];
		else
			return (printf("Error: invalid character in map\n"), 0);	
		j++;
	}
	while(i < map->map_width)
	{
		map->map[i][j] = ' ';
		i++;
	}
	map->map[i][j] = '\0';
	return (1);
}
int has_single_player(char **map)
{
	int i = 0, j;
	int player_count = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W')
			{
				player_count++;
				if (player_count > 1)
					return (printf("❌ Error: multiple players found\n"), 0);
			}
			j++;
		}
		i++;
	}
	if (player_count == 0)
		return (printf("❌ Error: no player found in map\n"), 0);
	return (1);
}


// int has_single_player(char **str)
// {
// 	int i;
// 	int j;
// 	int player_count;

// 	i = 0;
// 	player_count = 0;
// 	while (str[i])
// 	{
// 		j = 0;
// 		while (str[i][j])
// 		{
// 			if (str[i][j] == 'N' || str[i][j] == 'S' || str[i][j] == 'E' || str[i][j] == 'W'))
// 				player_count++;
// 			else if (player_count && (str[i][j] == 'N' || str[i][j] == 'S' || str[i][j] == 'E' || str[i][j] == 'W'))
// 				return (printf("Error: multiple players detected\n"), 0);
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (!player_count)
// 		return (printf("Error: invalid number of players\n"), 0);
// 	return (1);
// }
// int surrouding_walls(char **map, int i, int j)
// {
// 	if (i == 0 || j == 0 || !map[i + 1] || !map[i - 1] || !map[i][j + 1] || !map[i][j - 1])
// 		return (0);
// 	if (!map[i - 1][j] || !map[i + 1][j] || !map[i][j - 1] || !map[i][j + 1])
// 		return (0);
// 	return (1);
// }

// int surrouding_walls(char **map,int i,int j)
// {
// 	if ((i == 0 || j == 0) && map[i][j] == '0')
// 		return (0);
// 	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' 
// 		|| map[i][j - 1] == ' ' || map[i][j + 1] == ' ' 
// 		|| !map[i - 1][j] || !map[i + 1][j] 
// 		|| !map[i][j - 1] || !map[i][j + 1])
// 		return (0);
// 	return (1);
// }
int surrouding_walls(char **map, int i, int j)
{
	if (i == 0 || j == 0 || !map[i + 1] || !map[i - 1] || !map[i][j + 1] || !map[i][j - 1])
		return (0);

	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' '
	 || map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
		return (0);

	return (1);
}

