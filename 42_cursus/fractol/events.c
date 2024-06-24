#include "fractol.h"

int key_handler(int keycode, t_fractal *fractal)
{
    if(keycode == 65307)
        close_handler(fractal);
    if(keycode == 65361)
        fractal->shift_x -= 0.5 *fractal->zoom; //left
    else if(keycode == 65363)
        fractal->shift_x += 0.5 *fractal->zoom; //right
    else if(keycode == 65362)
        fractal->shift_y += 0.5 *fractal->zoom; //up
    else if(keycode == 65364)
        fractal->shift_y -= 0.5 *fractal->zoom; //down
    else if(keycode== 61)
        fractal->max_iterations += 10;
    else if(keycode == 45)
        fractal->max_iterations -= 10;
    fractal_render(fractal);
}
int mouse_handler(int button ,int x, int y ,t_fractal *fractal)
{
    if(button == 5)
    {
        fractal->zoom *= 0.95;
    }
    else if(button == 4)
    {
        fractal->zoom *= 1.5;
    }
    fractal_render(fractal);
}
int close_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection,fractal->image_ptr);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
    exit(EXIT_SUCCESS);
}