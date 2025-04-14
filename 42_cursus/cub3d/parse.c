#include "cub.h"
// int parse_line(char *line, t_info *map)
// {
// 	static int width;
// 	static int height;
// 	int i;
// 	int j;

// 	width = 0;
// 	height = 0;
// 	// if(!line || line[0] == '\0' || line[0] == '\n')
// 	// 	return(1);
// 	if (!line || ft_strlenwnl(line) == 0)
// 	return (1);
// 	i = parse_texture(line, map);
// 	if(i == 1 || i == 0)
// 		return(i);
// 	j = parse_color(line, map);
// 	if(j == 1 || j == 0)
// 		return(j);
// 	printf("TEXT_COLOR: %d | LINE: [%s]\n", text_color(map), line);

// 	if(text_color(map) && is_valid_map(line[0]))
// 	{
// 		height++;
// 		if(ft_strlenwnl(line) > width)
// 			width = ft_strlenwnl(line);
// 	}
// 	else
// 		return(printf("Error: invalid character found in file\n"), 0);
// 	map->map_width = width;
// 	map->map_height = height + 1;
// 	return(1);
// }
int parse_line(char *line, t_info *map)
{
	static int width;
	static int height;
	int i;
	int j;

	width = 0;
	height = 0;

	if (!line || is_line_empty(line))
	return (1);
	i = parse_texture(line, map);
	if (i == 1 || i == 0)
		return (i);
	j = parse_color(line, map);
	if (j == 1 || j == 0)
		return (j);

	if (is_valid_map(line[0]))
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
int parse_map(t_info *map, char *path)
{
	if(!load_map_file(map,path))
		return(0);
	return(1);
}