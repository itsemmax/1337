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

void    handle_pixel(double x, double y, t_fractal *fractal)
{
    double temp;
    int i;

    i = 0;
    fractal->zx = 0.0;
    fractal->zy = 0.0;
    fractal->cx = map(x, -2, 2);
    fractal->cy = map(y, 2, -2);
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

void    fractal_render(t_fractal *fractal)
{
    fractal->y = -1;
    while(++fractal->y < HEIGHT)
    {
        fractal->x = -1;
        while(++fractal->x < WIDTH)
        {
            handle_pixel(fractal->x, fractal->y, fractal);
        }
    }
}