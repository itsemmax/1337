#ifndef CUB_H
#define CUB_H

#include <stdio.h>
#include <unistd.h>
#include "mlx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

# define HEIGHT 640
# define WIDTH 1000
#define CUBE_SIZE 32
#define MINI_MAP_SIZE 8
#define SPEED 10.0
#define ROTATE_SPEED 0.06

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			endian;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			is_init;
}	t_texture;

typedef struct s_info
{
	t_texture *no_texture;
	t_texture *so_texture;
	t_texture *we_texture;
	t_texture *ea_texture;
	int floor_color;
	int ceiling_color;
	char **map;
	int map_width;
	int map_height;
	int player_x;
	int player_y;
	int mini_pos_x;
	int mini_pos_y;
	char player_dir;
	int speed;
	void *mlx;
	void *win;
}	t_info;

int ft_strlen(char *str);
int	check_extension(char *str);
void init(t_info *map);
int parse_map(t_info *map, char *path);
int load_map_file(t_info *map,char *path);
int init_ea_texture(t_info *map);
int init_map(t_info *map);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
int parse_line(char *line, t_info *map);
int ft_strlenwnl(char *str);
char *ft_dupwnl(char *str);
int parse_texture(char *line, t_info *map);
int parse_color(char *line, t_info *map);
int text_color(t_info *map);
int is_valid_char(char c);
int ft_strncmp(char *s1, char *s2, int n);
int load_texture(t_info *map, t_texture *texture, char *path);
int add_texture(char *line, t_info *map, t_texture *texture, char *texture_name);
int	add_color(char *line, int *color, char color_type);
int free_texture(t_info *map);
char **ft_split(char const *s, char c);
int	parse_rgb_color(char *line);
int split_len(char **str);
int free_array(char ***str, int a);
int check_valid_color(char *str);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
void strip_trailing_whitespace(char *str);
int is_line_empty(char *line);
int allocate_map_grid(t_info *map,int height, int width);
void free_map(char ***map,int a);
int fill_map_grid(char *path, t_info *map);
int is_valid_map(char *line);
int has_single_player(char **str);
int is_map_enclosed(char **map);
char *ft_strchr(const char *s, int c);
int fill_map(char *line,t_info *map,int i);
int surrouding_walls(char **map,int i,int j);
void set_player_start_position(t_info *map);
#endif