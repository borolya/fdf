/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:32:22 by bharmund          #+#    #+#             */
/*   Updated: 2019/07/19 21:32:23 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int close_win(t_fdf *fdf)
{
    int i;

    mlx_destroy_image(fdf->mlx_ptr, fdf->img->ptr);
    mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
    ft_memdel((void**)&(fdf->img));
    ft_memdel((void**)&(fdf->scene));
    i = 0;
    while(i < fdf->map->h)
    {
        ft_memdel((void**)&(fdf->map->crd[i]));
        i++;
    }
    ft_memdel((void**)&(fdf->map->crd));
    ft_memdel((void**)&(fdf)); 
    exit(0);
}

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
    if (keycode == 53)
        close_win(fdf);
    if (keycode == 24 || keycode == 27 || keycode == 15 || keycode == 17 ||
        keycode == 14 || keycode == 13 || keycode == 2 || keycode == 1)
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
                else if (keycode == 15)
                    rotate(&(fdf->map->crd[i][j]), 1, 1);
                else if (keycode == 17)
                    rotate(&(fdf->map->crd[i][j]), 1, -1);
                else if (keycode == 14)
                    rotate(&(fdf->map->crd[i][j]), 3, 1);
                else if (keycode == 13)
                    rotate(&(fdf->map->crd[i][j]), 3, -1);
                else if (keycode == 2)
                    rotate(&(fdf->map->crd[i][j]), 2, 1);
                else if (keycode == 1)
                    rotate(&(fdf->map->crd[i][j]), 2, -1);
                j++;
            }
            i++;
        }
    }
    else if (keycode == 29)
        fdf->projection = 0;
    else if (keycode == 18)
        fdf->projection = 1;
    else if (keycode == 19)
        fdf->projection = 2;
    mlx_destroy_image (fdf->mlx_ptr, fdf->img->ptr);
    init_image(fdf->mlx_ptr, fdf->img);
    draw_map(take_dis_crd(fdf, fdf->scene->tr_matrix), *(fdf->map), fdf->img);
    mlx_put_image_to_window((fdf)->mlx_ptr, (fdf)->win_ptr, (fdf)->img->ptr, 150, 150);
    return (0);
}
