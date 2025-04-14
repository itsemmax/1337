#include "cub.h"

int parse_texture(char *line, t_info *map)
{
	if(ft_strncmp(line, "NO ", 3) == 0)
	{
		if(!add_texture(line, map, map->no_texture, "NO"))
			return (0);
		return(1);
	}
	else if(ft_strncmp(line, "SO ", 3) == 0)
	{
		if(!add_texture(line, map, map->so_texture, "SO"))
			return (0);
		return(1);
	}
	else if(ft_strncmp(line, "WE ", 3) == 0)
	{
		if(!add_texture(line, map, map->we_texture, "WE"))
			return (0);
		return(1);
	}
	else if(ft_strncmp(line, "EA ", 3) == 0)
	{
		if(!add_texture(line, map, map->ea_texture, "EA"))
			return (0);
		return(1);
	}
	return (-1);
}
int text_color(t_info *map)
{
	if(!map->no_texture->img || !map->so_texture->img || !map->we_texture->img || !map->ea_texture->img)
		return (0);
	if(map->floor_color == -1 || map->ceiling_color == -1)
		return (0);
	return (1);
}
int load_texture(t_info *map, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(map->mlx, path, &texture->width, &texture->height);
	if(!texture->img)
		return (printf("Error: failed to load texture\n"), 0);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, &texture->line_length, &texture->endian);
	if(!texture->addr)
		return (printf("Error: failed to get texture data address\n"), 0);
	return (1);
}
int	add_texture(char *line, t_info *map, t_texture *texture, char *texture_name)
{
	int i;
	char *raw_path;
	char *path;

	if (texture->is_init)
		return (printf("double definition of texture (%s)\n", texture_name), 0);
	i = 2;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	raw_path = ft_dupwnl(&line[i]);
	if (!raw_path)
		return (printf("malloc failed\n"), 0);
	strip_trailing_whitespace(raw_path);
	path = ft_strdup(raw_path);
	free(raw_path);
	if (!path)
		return (printf("malloc failed\n"), 0);
	if (!load_texture(map, texture, path))
	{
		free(path);
		return (0);
	}
	texture->is_init = 1;
	free(path);
	return (1);
}

