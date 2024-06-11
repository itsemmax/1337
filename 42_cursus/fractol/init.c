#include "fractol.h"

static void malloc_error(void)
{
    perror("Problems with malloc");
    exit(EXIT_FAILURE);
}

void    data_init(t_fractal *fractal)
{
    fractal->escape_value = 4; //,x ^2 + y^2  hypertenuse
    fractal->max_iterations = 42;
}

void    fractal_init(t_fractal   *fractal)
{
    fractal->mlx_connection = mlx_init();
    if(fractal->mlx_connection == NULL)
        malloc_error();
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
                                        WIDTH, HEIGHT, fractal->name);
    if(fractal->mlx_window == NULL)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
    }
    fractal->image_ptr = mlx_new_image(fractal->mlx_connection,
                                        WIDTH, HEIGHT);
    {
        mlx_destroy_window(fractal->mlx_connection,fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
    }
    fractal->pixels_ptr = mlx_get_data_addr(fractal->image_ptr,
                                            &fractal->bpp,
                                            &fractal->line_len,
                                            &fractal->endian);                          

}