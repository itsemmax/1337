#include "fractol.h"

/*
[0,799] ----> [-2,2]/!\  
*/
double  map(double unscaled_num, double new_min, double new_max)
{
    double old_min = 0;
    double old_max = 799;
    return(new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}