#include "fdf.h"

int **take_dis_crd(t_fdf *fdf)
{
    int i;
    int j;
    int **dis_crd;
    t_map *map;
    double *tr_matrix;


    map = fdf->map;
    if (transformation_matrix(fdf->scene, &tr_matrix))
        return (NULL);
    if(!(dis_crd = ft_memalloc(sizeof(int*) * map->h)))
        return (NULL);

    i = 0;
    while(i < map->h)
    {
        if(!(dis_crd[i] = ft_memalloc(sizeof(int) * map->w)))
            return(NULL);
        j = 0;
        while (j < map->w)
        {
           dis_crd[i][j] = projection(take_al_coord(tr_matrix, map->crd[i][j], fdf->scene));
            j++;
        }
        i++;
    }
    return (dis_crd);
}


int init_image(void *mlx_ptr, t_img *img)
{
    img->w = 500;
    img->h = 500;
    img->ptr = mlx_new_image(mlx_ptr, img->w, img->h);
    img->data = (int*)mlx_get_data_addr (img->ptr, &(img->b_p_pixel), &(img->s_l), &(img->endian));
}

int init_scene(t_scene *scene, t_map *map)
{
    scene->lookAt.x = map->w / 2;
    scene->lookAt.y = map->h / 2;
    scene->lookAt.z = (map->depth_max + map->depth_min) / 2;

    scene->eye.x = map-> w * 1,5;
    scene->eye.y = map-> h * 1,5;
    scene->eye.z = map->depth_max + (map->depth_max - map->depth_min) / 2;

    scene->up.x = 0;
    scene->up.y = 0;
    scene->up.z = 1;
    return (0);
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
    if (init_scene((*fdf)->scene, map))
        return (1);
    (*fdf)->mlx_ptr = mlx_init();
    (*fdf)->win_ptr = mlx_new_window((*fdf)->mlx_ptr, (*fdf)->win_w, (*fdf)->win_h, "fdf");
    if (init_image((*fdf)->mlx_ptr, (*fdf)->img))
        return (1);
    draw(take_dis_crd(*fdf));
    return (0);
}