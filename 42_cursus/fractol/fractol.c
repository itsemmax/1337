//#include "minilibx-linux/mlx.h"
#include "minilibx_opengl_20191021/mlx.h"
#include "minilibx_mms_20191025_beta/mlx.h"
#include<mlx.h>
#include <stdlib.h>
//#include <X11/keysym.h>
#define MALLOC_ERROR    1

int main()
{
    void *mlx_connection;
    void *window;

    mlx_connection = mlx_init();
    if(mlx_connection == NULL)
        return(MALLOC_ERROR);
    window = mlx_new_window(mlx_connection, 1000, 800, "emma");
    if(window == NULL)
    {
        mlx_destroy_window(mlx_connection,window);
    	//mlx_destroy_display(mlx_connection);
        free(mlx_connection);
    }
    mlx_loop(mlx_connection);
    mlx_destroy_window(mlx_connection,window);
  // mlx_destroy_display(mlx_connection);
    free(mlx_connection);
}