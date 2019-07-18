#include "fdf.h"


#include <stdio.h>

int transformation_matrix(t_scene *scene, double **tr_matrix)
{
  t_point w;
  t_point u;
  t_point v;
  double length;

  if (!(*tr_matrix = ft_memalloc(sizeof(double)* 9)))
    return (1);
 // print_point(eye);
  //print_point(lookAt);
 // print_point(up);
  
  w = vector_min(scene->lookAt, scene->eye);
  v = vector_product(w, scene->up);
  u = vector_product(w, v);

 // print_point(w);
  //print_point(v);
  //print_point(u);

//    return (dell)
           // error;
    //if length == 0? 
  length = vector_length(v);
  if (length < 0.000001)
    printf("bad length v");
  (*tr_matrix)[0] = v.x / length;
  (*tr_matrix)[1] = v.y / length;
  (*tr_matrix)[2] = v.z / length;
  length = vector_length(u);
  if (length < 0.000001)
    printf("bad length u");
  (*tr_matrix)[3] = u.x / length;
  (*tr_matrix)[4] = u.y / length;
  (*tr_matrix)[5] = u.z / length;
  length = vector_length(w);
  if (length < 0.000001)
    printf("bad length w");
  (*tr_matrix)[6] = w.x / length;
  (*tr_matrix)[7] = w.y / length;
  (*tr_matrix)[8] = w.z / length;
    return (0);
}
