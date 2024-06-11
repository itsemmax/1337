#include"fractol.h"

/*
z = z^2 + c
z initially is (0,0)
and c is the actual point
*/

static  void put_color_to_pixel(int x, int y, t_fractal *fractal, int color)
{
    
}

void    handle_pixel(double x, double y, t_fractal *fractal)
{
    double temp;
    int i;

    i = 0;
    fractal->zx = 0.0
    fractal->zy = 0.0
    fractal->cx = map(x, -2, 2, 0, WIDTH);
    fractal->cy = map(y, 2, -2, 0, HEIGHT);
    while(i < fractal->max_iterations)
    {
        temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
		    + fractal->cx;
	    fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
	    fractal->zx = temp;
        if((fractal->zx * fractal->zx) + (fractal->zy * fractal->zy) > fractal->escape_value)
        {
            fractal->color = (i, BLACK, WHITE, 0, fractal->max_iterations);
            put_color_to_pixel();
        }
    }
    i++;

}

void    fractal_render(t_fractal *fractal)
{
    fractal->y = -1;
    while(++y < HEIGHT)
    {
        fractal->x = -1;
        while(++x < WIDTH)
        {
            handle_pixel(fractal->x, fractal->y, fractal);
        }
    }
}