#include "fdf.h"

#include <stdio.h>
/*void print_dis_crd(dis_point **crd, t_map map)
{
int i;
int j;

i = 0;
while (i < map.h)
{
    j = 0;
    while (j < map.w)
    {
        printf("i = %d j = %d x = %d y = %d\n", i, j, crd[i][j].x, crd[i][j].y);
        j++;
    }
    i++;
}
}
*/
dis_point **take_dis_crd(t_fdf *fdf)
{
    int i;
    int j;
    dis_point **dis_crd;
    t_map *map;
    double *tr_matrix;

    t_point tmp;

    map = fdf->map;
    if (transformation_matrix(fdf->scene, &tr_matrix))
        return (NULL);
    if(!(dis_crd = ft_memalloc(sizeof(dis_point*) * map->h)))
        return (NULL);

    i = 0;
    while(i < map->h)
    {
        if(!(dis_crd[i] = ft_memalloc(sizeof(dis_point) * map->w)))
            return(NULL);
        j = 0;
        while (j < map->w)
        {
            //printf("i = %d j = %d \n", i, j);
            tmp = take_al_coord(tr_matrix, map->crd[i][j], fdf->scene);
           // printf("in al_crd x = %lf y = %lf z = %lf\n", tmp.x, tmp.y, tmp.z);
           dis_crd[i][j] = projection(tmp, fdf->projection);
            //   printf("in displ x = %d y = %d\n", dis_crd[i][j].x, dis_crd[i][j].y);
            j++;
        }
        i++;
    }
   // print_dis_crd(dis_crd, *(fdf->map));
    return (dis_crd);
}


int init_image(void *mlx_ptr, t_img *img)
{
    img->w = 700;
    img->h = 700;
    img->ptr = mlx_new_image(mlx_ptr, img->w, img->h);
    img->data = (int*)mlx_get_data_addr(img->ptr, &(img->b_p_pixel), &(img->s_l), &(img->endian));
    return (0);
}

int max(int x, int y, int z)
{
    if (x < y && y > z)
        return (y);
    if (x < z && y < z)
        return (z);
    return (x);
}
int init_scene(t_scene *scene, t_map *map, int projection)
{
    int eye;

    eye = max(map->w * 1.5, map->h * 1.5, map->depth_max + (map->depth_max - map->depth_min) / 2); 
    projection = 1;

   /*
    if (projection == 1)
    {
    scene->lookAt.x = map->w / 2;
    scene->lookAt.y = map->h / 2;
    scene->lookAt.z = (map->depth_max + map->depth_min) / 2;

    scene->eye.x = map->w * 1.5;
    scene->eye.y = map->h * 1.5;
    scene->eye.z = map->depth_max + (map->depth_max - map->depth_min) / 2;
    }
    else 
    {
     */   
    scene->lookAt.x = 0;
    scene->lookAt.y = 0;
    scene->lookAt.z = 0;

    scene->eye.x = eye;
    scene->eye.y = eye;
    scene->eye.z = eye;
    //}
    scene->up.x = 0;
    scene->up.y = 0;
    scene->up.z = 1;
    return (0);
}

void all_red(int x, int y, int *data)
{
    int i;
    int j;

    i = 0;
    while(i < y)
    {
        j = 0;
        while(j < x)
        {
            data[i * x + j ] = 8383838;
            j++;
        }
    i++;
    } 
}

int init_fdf(t_fdf **fdf, t_map *map)
{
    if(!(*fdf = ft_memalloc(sizeof(t_fdf))))
        return (1);
    (*fdf)->win_w = 1000;
    (*fdf)->win_h = 1000;
    (*fdf)->zoom = 50;
    (*fdf)->projection = 1;
    if(!((*fdf)->img = ft_memalloc(sizeof(t_img))))
        return (1);
    if(!((*fdf)->scene = ft_memalloc(sizeof(t_scene))))
        return (1);
    (*fdf)->map = map;
    if (init_scene((*fdf)->scene, map, (*fdf)->projection))
        return (1);
    (*fdf)->mlx_ptr = mlx_init();
    (*fdf)->win_ptr = mlx_new_window((*fdf)->mlx_ptr, (*fdf)->win_w, (*fdf)->win_h, "fdf");
    if (init_image((*fdf)->mlx_ptr, (*fdf)->img))
            return (1);
    draw_map(take_dis_crd(*fdf), *((*fdf)->map), (*fdf)->img);
    mlx_put_image_to_window((*fdf)->mlx_ptr, (*fdf)->win_ptr, (*fdf)->img->ptr, 50, 50);

    return (0);
}