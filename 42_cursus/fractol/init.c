#include "fractol.h"

static void malloc_error(void)
{
    perror("Problems with malloc");
    exit(EXIT_FAILURE);
}

void data_init(t_fractal *fractal)
{
    fractal->escape_value = 4; //,x ^2 + y^2  hypertenuse
    fractal->max_iterations = 1200;
}

void events_init(t_fractal *fractal)
{
    mlx_hook(fractal->mlx_window,
             KeyPress,
             KeyPressMask,
             key_handler,
             fractal);
    mlx_hook(fractal->mlx_window,
             ButtonPress,
             ButtonPressMask,
             key_handler,
             fractal);
    mlx_hook(fractal->mlx_window,
             DestroyNotify,
             StructureNotifyMask,
             key_handler,
             fractal);
}

void fractal_init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if (!fractal->mlx_connection)
        malloc_error();
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
                                         WIDTH, HEIGHT, fractal->name);
    if (!fractal->mlx_window)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        //  free(fractal);
        malloc_error();
    }
    fractal->image_ptr = mlx_new_image(fractal->mlx_connection,
                                       WIDTH, HEIGHT);
    if (!fractal->image_ptr)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        //    free(fractal);
        malloc_error();
    }
    fractal->pixels_ptr = mlx_get_data_addr(fractal->image_ptr,
                                            &fractal->bpp,
                                            &fractal->line_len,
                                            &fractal->endian);
    events_init(fractal);
    data_init(fractal);
}