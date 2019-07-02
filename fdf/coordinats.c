#include "fdf.h"
//потом надо будет нормализовать векторыыыыыы
//void from_matrix_to_coordinate(int **matrix, int max)

t_point vector_sum(t_point u, t_point v)
{
  t_point w;

  w.x = u.x + v.x;
  w.y = u.y + v.y;
  w.z = u.z + v.z;
   return (w);
}

t_point const_dot_vector(double a, t_point v)
{
  t_point w;

  w.x = a * v.x;
  w.y = a * v.y;
  w.z = a * v.z;

  return (w);
}

double vector_length(t_point v)
{
  double lenth;

  lenth = v.x*v.x + v.y*v.y + v.z*v.z;
  lenth = sqrt(lenth);
  return (lenth);
}


t_point vector_product(t_point u, t_point v)
{
  t_point w;

  w.x = u.y*v.z - u.z*v.y;
  w.y = - u.x*v.z + u.z*v*x;
  w.z = u.x*v.y - u.y*v.x;
  return (w);
}

t_point matrix_dot_vector(double *matrix, t_point v)
{
  t_point w;

  w.x = v.x * matrix[0] + v.y * matrix[1] + v.z * matrix[2];
  w.y = v.x * matrix[3] + v.y * matrix[4] + v.z * matrix[5];
  w.x = v.x * matrix[6] + v.y * matrix[7] + v.z * matrix[8];
  return (t_point); 
}
 

void initialization(t_point size_map)//need by maps parametrs
{
  t_point eye; //why we use *?
  t_point lookAt;
  t_point up;
  double N;

  eye->x = EYE;
  eye->y = EYE;
  eye->z = EYE;

  lookAt.x = size_map.x/2;
  lookAt.y = size_map.y/2;
  lookAt.z = size_map.z/2;

  up.x = 0;
  up.y = 0;
  up.z = 1;
}

t_point *from_world_to_aligned(double *tr_matrix, int **matrix, t_point eye, t_point size_map)
{
  t_point *coord;
  int i;
  int j;
  t_point tmp;

  if (!(coord = ft_memmalloc(sizeof(t_point) * size_map.x * size_map.y)))
    error;
    i = 0;
  while (i < size_map.y)
  {
    j = 0;
    while (j < size_map.x)
    {
      tmp.x = j;
      tmp.y = i;
      tmp.z = matrix[i][j];
      (coord[i * size_map.x + j]) = vector_sum(matrix_dot_vector(tr_matrix, tmp), eye);
      j++; 
    }
    i++;
  }
}

/*
t_dis_point *from_aligned_to_display(double N, t_point *al_coord, t_point size_map)
{
  t_dis_point *dis;
  int i;
  int j;

  if (!(dis = ft_memmalloc(sizeof(t_dis_point) * size_map.x * size_map.y)))
    error;
    i = 0;
  while (i < size_map.y)
  {
    j = 0;
    while (j < size_map.x)
    {
      (coord_dis[i * size_map.x + j]).x = 
    }
    i++;
  }

}
*/

double *create_Transformation_matrix(t_point eye, t_point lookAt, t_point up)
{
  double *tr_matrix;
  t_point w;
  t_point u;
  t_point v;
  double length;

  w = vector_substraction(lookAt, const_dot_vector(-1, eye));
  v = vector_product(w, up);
  u = vector_product(w, v);

  if (!(tr_matrix = ft_memmalloc(sizeof(double) * 9)))
    error;
    //if length == 0? 
  length = vector_length(v);
  tr_matrix[0] = w.x / length;
  tr_matrix[3] = w.y / length;
  tr_matrix[6] = w.z / length;
  length = vector_length(u);
  tr_matrix[1] = w.x / length;
  tr_matrix[4] = w.y / length;
  tr_matrix[7] = w.z / length;
  length = vector_length(w);
  tr_matrix[2] = w.x / length;
  tr_matrix[5] = w.y / length;
  tr_matrix[8] = w.z / length;
  return (tr_matrix);
}