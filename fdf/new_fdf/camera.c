#include "fdf.h"

int scene_initialization(t_scene **scene, t_map **map)
{
    if (! (*scene = ft_memaloc(sizeof(t_scene))))
        return (del_list_map(NULL, map, 0));
    (*scene)->lookAt.x = (*map)->w / 2;
    (*scene)->lookAt.y = (*map)->h / 2;
    (*scene)->lookAt.z = ((*map)->depth_max + (*map)->depth_min) / 2;

    (*scene)->eye.x = (*map)-> w * 1,5;
    (*scene)->eye.y = (*map)-> h * 1,5;
    (*scene)->eye.z = (*map)->depth_max + ((*map)->depth_max - (*map)->depth_min) / 2;

    (*scene)->up.x = 0;
    (*scene)->up.y = 0;
    (*scene)->up.z = 1;

    //?
    (*scene)->N = 10;
    return (0);
}


int create_Transformation_matrix(t_scene *scene, double **tr_matrix)
{
  t_point w;
  t_point u;
  t_point v;
  double length;

 // print_point(eye);
  //print_point(lookAt);
 // print_point(up);
  
  w = vector_sum(scene->lookAt, const_dot_vector(-1, scene->eye));
  v = vector_product(w, scene->up);
  u = vector_product(w, v);

 // print_point(w);
  //print_point(v);
  //print_point(u);

  if(! (*tr_matrix = ft_memalloc(sizeof(double) * 9)))
//    return (dell)
           // error;
    //if length == 0? 
  length = vector_length(v);
  *tr_matrix[0] = v.x / length;
  *tr_matrix[1] = v.y / length;
  *tr_matrix[2] = v.z / length;
  length = vector_length(u);
  *tr_matrix[3] = u.x / length;
  *tr_matrix[4] = u.y / length;
  *tr_matrix[5] = u.z / length;
  length = vector_length(w);
  *tr_matrix[6] = w.x / length;
  *tr_matrix[7] = w.y / length;
  *tr_matrix[8] = w.z / length;
    return (0);
}

int take_al_coord(t_map *map, t_point ***al_crd)
{
    t_scene *scene;
    double *tr_matrix;
    int i;
    int j;

    scene_initialization(&scene, &map);
    create_Transformation_matrix(scene, &tr_matrix);
    *al_crd = ft_memalloc(sizeof(t_point*) * map->h);
    //error
    i = 0;
    while (i < map->h)
    {
        (*al_crd)[i] = ft_memalloc(sizeof(t_point) * map->w);
        //error
        j = 0;
        while(j < map->w)
        {
            (*al_crd)[i][j] = matrix_dot_vector(tr_matrix, 
                                vector_min(map->crd[i][j],scene->eye));
            j++;
        }
        i++;
    }
    return (0);
}