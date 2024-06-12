#include "fractol.h"
#include<stdio.h>

/*
[0,799] ----> [-2,2]/!\  
*/
double  map(double unscaled_num, double new_min, double new_max)
{
    double old_min = 0;
    double old_max = 799;
    return(new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

void    get_value(int argc, char **argv, t_fractal *fractal)
{
    if(argc == 2)
    {
        fractal->julia_cx = -0.745429;
	    fractal->julia_cy = 0.05; 
    }
    else
    {
        if(!check_arg(argv[2]) && !check_arg(argv[3]))
        {
            fractal->julia_cx = ft_get_double(argv[2]);
            fractal->julia_cy = ft_get_double(argv[3]);
        }
        else
        {
            write(2, "Error: wrong format. Try: ./fractol mandelbrot\n or ./fractol julia\n or ./fractol julia <x> <y>\n", 96);
		    exit(EXIT_FAILURE);
        }
    }
}

int check_arg(char *str)
{
    int i;
    int sign;
    int check;

    i = 0;
    sign = 0;
    check = 0;

    while(str[i] && str)
    {
        if(str[i] = 0)
            return(0);
        if(str[i] == '+' || str[i] == '-')
            sign++;
        if(str[i] == '.')
            check++;
        i++;
    }
    if(check == 0)
        return(0);
    if(sign > 1 || check > 1)
        return(0);
    else
        return(1);

}
double    	ft_get_double(char *str)
{
    printf("m3eraftch nsawbha");
}