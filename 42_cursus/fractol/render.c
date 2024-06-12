#include"fractol.h"

/*
*put a pixel in my image  buffer
*/

static  void put_pixel(int x, int y, t_fractal *fractal, int color)
{
    int offset;
    offset = (y * fractal->line_len) + (x * fractal->bpp / 8);
    *(unsigned int *)(fractal->pixels_ptr + offset) = color;
}
/*
z = z^2 + c
z initially is (0,0)
and c is the actual point
*/

void    draw_mandelbrot(double x, double y, t_fractal *fractal)
{
    double temp;
    int i;

    i = 0;
    fractal->zx = 0.0;
    fractal->zy = 0.0;
    fractal->cx = map(x, -2, 2) * fractal->zoom;
    fractal->cy = map(y, 2, -2) * fractal->zoom;
    while(i < fractal->max_iterations)
    {
        temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
		    + fractal->cx;
	    fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
	    fractal->zx = temp;
        if((fractal->zx * fractal->zx) + (fractal->zy * fractal->zy) > fractal->escape_value)
        {
            fractal->color = (i, BLACK, WHITE, 0, fractal->max_iterations);
            put_pixel(fractal->x, fractal->y, fractal, fractal->color);
            return;
        }
        put_pixel(fractal->x, fractal->y, fractal, RED);
    }
    i++;

}

void    draw_julia(double x, double y, t_fractal *fractal)
{
    double temp;
    int i;

    i = 0;
    fractal->zx = map(x, -2, +2);
    fractal->zy = map(y, 2, -2);
    fractal->cx = fractal->julia_cx;
    fractal->cy = fractal->julia_cy;
    while(i < fractal->max_iterations)
    {
        temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
		    + fractal->cx;
	    fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
	    fractal->zx = temp;
        if((fractal->zx * fractal->zx) + (fractal->zy * fractal->zy) > fractal->escape_value)
        {
            fractal->color = map(i, BLACK, WHITE);
            put_pixel(fractal->x, fractal->y, fractal, fractal->color);
            return;
        }
        put_pixel(fractal->x, fractal->y, fractal, RED);
    }
    i++;

}

void    fractal_render(t_fractal *fractal)
{
    fractal->y = -1;
    while(++fractal->y < HEIGHT)
    {
        fractal->x = -1;
        while(++fractal->x < WIDTH)
        {
            if(!ft_strncmp(fractal->name,"mandelbrot",10))
                draw_mandelbrot(fractal->x, fractal->y, fractal);
            else if(!ft_strncmp(fractal->name,"julia",5))
                draw_julia(fractal->x, fractal->y, fractal);
        }
        mlx_clear_window(fractal->mlx_connection,fractal->mlx_window);
        mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,fractal->image_ptr,0,0);
    }
}
