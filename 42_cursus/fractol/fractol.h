#ifndef FRACTOL_H
#define FRACTOL_H
#include "minilibx-linux/mlx.h"
#include<mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>
#define WIDTH	800
#define HEIGHT	800
#define BLACK   0x000000
#define WHITE   0xFFFFFF
#define RED     0xFF0000
#define GREEN   0x00FF00
#define BLUE    0x0000FF
#define YELLOW  0xFFFF00
#define CYAN    0x00FFFF
#define MAGENTA 0xFF00FF
#define DARK_RED    0x800000
#define DARK_GREEN  0x008000
#define DARK_BLUE   0x000080
#define ORANGE      0xFFA500
#define PURPLE      0x800080
#define BROWN       0xA52A2A
#define GRAY        0x808080
#define LIGHT_GRAY  0xD3D3D3
#define OLIVE       0x808000
#define TEAL        0x008080
#define NAVY        0x000080
#define PINK        0xFFC0CB
#define LAVENDER    0xE6E6FA
#define MAROON      0x800000
#define GOLD        0xFFD700
#define INDIGO      0x4B0082
#define TURQUOISE   0x40E0D0
#define SALMON      0xFA8072
#define SKY_BLUE    0x87CEEB
#define STEEL_BLUE  0x4682B4
#define VIOLET      0xEE82EE

typedef struct s_fractal
{
	void	*mlx_connection; //mlx init
	void	*mlx_window; //new_window
	void	*image_ptr; //pointer to image 
	void	*pixels_ptr; // points to the actual pixel
	int		bpp; // bits per pixel
	int		line_len; // Number of bytes in a single row of the image. This can be used to navigate the image buffer
	int		endian;  // Endianness of the image data (0 for little-endian, 1 for big-endian).
	int		x; // Current x-coordinate in the image.
	int		y; // Current y-coordinate in the image.
	double	zx; // real part of the complex number z.
	double	zy; // Imaginary part of the complex number z.
	double	cx;  // real part of the complex constant c.
	double	cy;  // Imaginary part of the complex constant c.
	double	julia_cx;
	double	julia_cy;
	int		color;  // Current color value used for drawing.
	double	zoom; // Zoom level for zooming in and out
	char	*name;  // Name of the fractal type
	int		max_iterations;
	double	escape_value;
}			t_fractal;

void    	fractal_init(t_fractal   *fractal);
void    data_init(t_fractal *fractal);
void    	fractal_render(t_fractal *fractal);
void    	draw_julia(double x, double y, t_fractal *fractal);
void    	draw_mandelbrot(double x, double y, t_fractal *fractal);
double  	map(double unscaled_num, double new_min, double new_max, double old_max);
int			check_arg(char *str);
double    	ft_get_double(char *str);
int	ft_strncmp(char *s1, char *s2, int n);
void    	get_value(int argc, char **argv, t_fractal *fractal);
int			exit_fractal(t_fractal *fractal);
void    events_init(t_fractal *fractal);
int key_handler(int keycode, t_fractal *fractal);
#endif