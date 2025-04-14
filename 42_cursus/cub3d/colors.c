#include "cub.h"

// int check_valid_color(char *str)
// {
//     char    *trim;
//     int     index;
//     int     value;

//     while (*str == ' ')
//         str++;
//     if (ft_strlenwnl(str) == 0)
//         return (-1);
//     trim = ft_dupwnl(str);
//     index = 0;
//     while (trim[index] && ft_isdigit(trim[index]))
//         index++;
//     while (trim[index])
//     {
//         if (trim[index] != ' ')
//         {
//             free(trim);
//             return (-1);
//         }
//         index++;
//     }
//     value = ft_atoi(trim);
//     free(trim);
//     return (value);
// }
// int check_valid_color(char *str)
// {
// 	while (*str == ' ' || *str == '\t')
// 		str++;
// 	if (*str == '\0')
// 		return (-1);
// 	int value = ft_atoi(str);
// 	while (*str && ft_isdigit(*str))
// 		str++;
// 	while (*str)
// 	{
// 		if (*str != ' ' && *str != '\t' && *str != '\n')
// 			return (-1);
// 		str++;
// 	}
// 	return value;
// }
int check_valid_color(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '\0')
		return (-1);
	int value = ft_atoi(str);
	while (*str && ft_isdigit(*str))
		str++;
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n')
			return (-1);
		str++;
	}
	return value;
}
void strip_trailing_whitespace(char *str)
{
	int len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t' || str[len - 1] == '\n' || str[len - 1] == '\r'))
	{
		str[len - 1] = '\0';
		len--;
	}
}
int parse_rgb_color(char *line)
{
	int r, g, b;
	char **split;

	split = ft_split(line, ',');
	if (!split)
		return (printf("malloc failed\n"), -1);
	if (split_len(split) != 3)
	{
		free_array(&split, 0);
		return (printf("invalid number of colors\n"), -1);
	}
	strip_trailing_whitespace(split[0]);
	strip_trailing_whitespace(split[1]);
	strip_trailing_whitespace(split[2]);
	r = check_valid_color(split[0]);
	g = check_valid_color(split[1]);
	b = check_valid_color(split[2]);
	free_array(&split, 0);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (printf("invalid color value\n"), -1);
	return (0 << 24 | r << 16 | g << 8 | b);
}
int	add_color(char *line, int *color, char color_type)
{
	int i;
	int col;

	if (*color != -1)
		return (printf("double definition of a color(%c)\n",color_type), 0);
	i = 1;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	col = parse_rgb_color(&line[i]);
	if (col < 0)
		return (0);
	*color = col;
	return (1);
}

int parse_color(char *line, t_info *map)
{
	if(ft_strncmp(line, "F ", 2) == 0)
	{
		if(!add_color(line, &map->floor_color, 'F'))
			return (0);
		return (1);
	}
	else if(ft_strncmp(line, "C ", 2) == 0)
	{
		if(!add_color(line, &map->ceiling_color, 'C'))
			return (0);
		return (1);
	}
	return (-1);
}