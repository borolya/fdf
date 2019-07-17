#include "fdf.h"

#include <stdio.h>

int rotate(t_point *p, int flag, int sign)
{
    double x;
    double y;
    double z;
    double a;

    x = p->x;
    y = p->y;
    z = p->z;
    a = sign * 0.17;
    if(flag == 1)
    {
        p->y = cos(a) * y - sin(a) * z;
        p->z = sin(a) * y + cos(a) * z;
    }
    if (flag == 2)
    {
        p->x = cos(a) * x + sin(a) * z;
        p->z = - sin(a) * x + cos(a) * z; 
    }
    if (flag == 3)
    {
        p->x = cos(a) * x + sin(a) * y;
        p->y = - sin(a) * x + cos(a) * y;
    }
    return (0);
}

int user_hook(int keycode, t_fdf *fdf)
{
    int i;
    int j;

    //printf("push %d \n", keycode);
    if (keycode == 24 || keycode == 27 || keycode == 8 || keycode == 6 ||
        keycode == 7 || keycode == 0 || keycode ==32 || keycode == 17)
    {
        
        i = 0;
        while (i < fdf->map->h)
        {
            j = 0;
            while (j < fdf->map->w)
            {
                if (keycode == 24)
                    fdf->map->crd[i][j] = const_dot_vector(1.2,  fdf->map->crd[i][j]);
                else if (keycode == 27)
                    fdf->map->crd[i][j] = const_dot_vector(0.8, fdf->map->crd[i][j]);
                else if (keycode == 8)
                    rotate(&(fdf->map->crd[i][j]), 1, 1);
                else if (keycode == 6)
                    rotate(&(fdf->map->crd[i][j]), 1, -1);
                else if (keycode == 7)
                    rotate(&(fdf->map->crd[i][j]), 3, 1);
                else if (keycode == 0)
                    rotate(&(fdf->map->crd[i][j]), 3, -1);
                else if (keycode == 32)
                    rotate(&(fdf->map->crd[i][j]), 2, 1);
                else if (keycode == 17)
                    rotate(&(fdf->map->crd[i][j]), 2, -1);
                j++;
            }
            i++;
        }
    }
    else if (keycode == 35)
        fdf->projection = 1;
    else if (keycode == 34)
        fdf->projection = 0;
    mlx_destroy_image (fdf->mlx_ptr, fdf->img->ptr);
    init_image(fdf->mlx_ptr, fdf->img);
    draw_map(take_dis_crd(fdf), *(fdf->map), fdf->img);
    mlx_put_image_to_window((fdf)->mlx_ptr, (fdf)->win_ptr, (fdf)->img->ptr, 50, 50);
    return (0);
}