#include "cub.h"

int parse_line(char *line, t_info *map)
{
	static int width;
	static int height;
	int i;
	int j;

	if (!line || is_line_empty(line))
	return (1);
	i = parse_texture(line, map);
	if (i == 1 || i == 0)
		return (i);
	j = parse_color(line, map);
	if (j == 1 || j == 0)
		return (j);

	if (is_valid_char(line[0]))
	{
		height++;
		if (ft_strlenwnl(line) > width)
			width = ft_strlenwnl(line);
	}
	else
		return (printf("Error: invalid character found in file\n"), 0);
	map->map_width = width;
	map->map_height = height + 1;
	return (1);
}

int load_map_file(t_info *map, char *path)
{
	int fd;
	char *line;
	int a;

	a = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return(printf("Error: file '%s' does not exist or cannot be opened\n", path), 0);
	if(!init_map(map))
		return(0);
	line = "";
	while(line)
	{
		line = get_next_line(fd);
		if(!a && !parse_line(line, map))
			a = 1;
		free(line);
	}
	close(fd);
	if (!text_color(map))
	{
		printf("Error: missing texture or color definitions\n");
		return (free_texture(map));
	}
	if(a == 1)
		return(free_texture(map));
	return(1);
}
int fill_map_grid(char *path, t_info *map)
{
	int fd;
	char *line;
	int i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return(printf("Error: file '%s' does not exist or cannot be opened\n", path), 0);
	line = "";
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (is_valid_map(line))
		{
			if (!fill_map(line, map, i))
			{
				free(line);
				close(fd);
				return (0);
			}
			i++;
		}
		free(line);
	}
	close(fd);
	return (1);
}
int is_map_enclosed(char **map)
{
	int i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(ft_strchr("EWNS",map[i][j]) && !surrouding_walls(map,i,j))
				return(printf("Error: map is not enclosed\n"), 0);
			if(map[i][j] == '0' && !surrouding_walls(map,i,j))
				return(printf("Error: map is not enclosed\n"), 0);
			j++;
		}
		i++;
	}
	return(1);
}
int parse_map(t_info *map, char *path)
{
	if (!load_map_file(map, path))
	return (0);
	if (!allocate_map_grid(map, map->map_height, map->map_width))
		return (free_texture(map));
	if (fill_map_grid(path, map) <= 0)
	{
		free_map(&map->map, 0);
		return (free_texture(map));
	}
	if (!has_single_player(map->map))
	{
		free_map(&map->map, 0);
		return (free_texture(map));
	}
	if (!is_map_enclosed(map->map))
	{
		free_map(&map->map, 0);
		return (free_texture(map));
	}
	set_player_start_position(map);
	return (1);
}