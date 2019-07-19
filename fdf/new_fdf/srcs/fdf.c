/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:32:01 by bharmund          #+#    #+#             */
/*   Updated: 2019/07/19 21:32:07 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

dis_point **take_dis_crd(t_fdf *fdf, double *tr_matrix)
{
    int i;
    int j;
    t_map *map;
    t_point tmp;

    map = fdf->map;
    i = 0;
    while(i < map->h)
    {
        j = 0;
        while (j < map->w)
        {
            if (fdf->projection != 2)
                tmp = matrix_dot_vector(tr_matrix, vector_min(map->crd[i][j],fdf->scene->eye));
            else 
                tmp = map->crd[i][j];
            fdf->dis_crd[i][j] = projection(tmp, fdf->projection);
            j++;
        }
        i++;
    }
    return (fdf->dis_crd);
}

void init_image(void *mlx_ptr, t_img *img)
{
    img->w = 700;
    img->h = 700;
    img->ptr = mlx_new_image(mlx_ptr, img->w, img->h);
    img->data = (int*)mlx_get_data_addr(img->ptr, &(img->b_p_pixel), &(img->s_l), &(img->endian));
}

double max(double x, double y, double z)
{
    if (x < y && y > z)
        return (y);
    if (x < z && y < z)
        return (z);
    return (x);
}

void init_scene(t_scene *scene, t_map *map)
{
    double eye;

    eye = max(map->w * 1.5, map->h * 1.5, map->depth_max + (map->depth_max - map->depth_min) / 2); 
    
    scene->lookAt.x = 0;
    scene->lookAt.y = 0;
    scene->lookAt.z = 0;

    scene->eye.x = eye;
    scene->eye.y = eye;
    scene->eye.z = eye;

    scene->up.x = 0;
    scene->up.y = 0;
    scene->up.z = 1;

    scene->tr_matrix = transformation_matrix(scene);
}

void init_dis_crd(t_fdf *fdf)
{
    int i;

    if(!(fdf->dis_crd = ft_memalloc(sizeof(dis_point*) * fdf->map->h)))
        exit(1);
    i = 0;
    while (i < fdf->map->h)
    {
       if(!(fdf->dis_crd[i] = ft_memalloc(sizeof(dis_point) * fdf->map->w)))
            exit(1);
        i++;
    }
}

int init_fdf(t_fdf *fdf, t_map *map)
{
    fdf->win_w = 1000;
    fdf->win_h = 1000;
    fdf->zoom = 50;
    fdf->projection = 1;
    if(!(fdf->img = ft_memalloc(sizeof(t_img))))
        exit(1);
    if(!(fdf->scene = ft_memalloc(sizeof(t_scene))))
        exit(1);
    fdf->map = map;
    init_scene(fdf->scene, map);
    fdf->mlx_ptr = mlx_init();
    fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_w, fdf->win_h, "fdf");
    init_image(fdf->mlx_ptr, fdf->img);
    init_dis_crd(fdf);
    draw_map(take_dis_crd(fdf, fdf->scene->tr_matrix), *(fdf->map), fdf->img);   
    mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->ptr, 150, 150);
    return (0);
}
