#include "fdf.h"
//потом надо будет нормализовать векторыыыыыы
//void from_matrix_to_coordinate(int **matrix, int max)




void initialization(t_point size_map, t_point *eye, t_point *lookAt, t_point *up, double *N)//need by maps parametrs
{
  *N = 300;
  eye->x = 15;
  eye->y = 15;
  eye->z = 15;

  lookAt->x = size_map.x/2;
  lookAt->y = size_map.y/2;
  lookAt->z = size_map.z/2;//z - 0? 

  up->x = 0;
  up->y = 0;
  up->z = 1;
}

t_point from_world_to_aligned(double *tr_matrix, int **matrix, t_point eye, t_point size_map, int i, int j)
{
  t_point tmp;

  tmp.x = j;
  tmp.y = i;
  tmp.z = matrix[i][j];
  //умножить на матр
  tmp = vector_sum(tmp, const_dot_vector(-1, eye));
  tmp = matrix_dot_vector(tr_matrix, tmp);
  return (tmp);
}

t_dis_point *from_world_to_display(double N, int  **matrix, t_point size_map, double *tr_matrix, t_point eye)
{
  t_dis_point *dis;
  int i;
  int j;
  t_point al_coord;

  dis = ft_memalloc(sizeof(t_dis_point) * size_map.x * size_map.y);
   // error;
    i = 0;
  while (i < size_map.y)
  {
    j = 0;
    while (j < size_map.x)
    {
      al_coord = from_world_to_aligned(tr_matrix, matrix, eye, size_map, i, j);
      printf( " i = %d j = %d N = %lf\n %lf %lf %lf\n ", i, j, N, al_coord.x , al_coord.y , al_coord.z);
      (dis[i * (int)size_map.x + j]).x = (int)((al_coord.x * N ) / al_coord.z);
      (dis[i * (int)size_map.x + j]).y = (int)((al_coord.y * N ) / al_coord.z);
      if ((dis[i * (int)size_map.x + j]).x < 0 || (dis[i * (int)size_map.x + j]).x >= img_width ||
                (dis[i * (int)size_map.x + j]).y < 0 || (dis[i * (int)size_map.x + j]).y >= img_height)
                {
                  printf("!!!!!  i = %d j = %d is not correct!!!", i, j);
                }
      //printf( " on display %d %d \n ", (dis[i * (int)size_map.x + j]).x , (dis[i * (int)size_map.x + j]).y );
      j++;
    }
    i++;
  }
  return (dis);
}

double *create_Transformation_matrix(t_point eye, t_point lookAt, t_point up)
{
  double *tr_matrix;
  t_point w;
  t_point u;
  t_point v;
  double length;

  print_point(eye);
  print_point(lookAt);
  print_point(up);
  
  w = vector_sum(lookAt, const_dot_vector(-1, eye));
  v = vector_product(w, up);
  u = vector_product(w, v);

  print_point(w);
  print_point(v);
  print_point(u);

  tr_matrix = ft_memalloc(sizeof(double) * 9);
        // error;
    //if length == 0? 
  length = vector_length(v);
  tr_matrix[0] = v.x / length;
  tr_matrix[1] = v.y / length;
  tr_matrix[2] = v.z / length;
  length = vector_length(u);
  tr_matrix[3] = u.x / length;
  tr_matrix[4] = u.y / length;
  tr_matrix[5] = u.z / length;
  length = vector_length(w);
  tr_matrix[6] = w.x / length;
  tr_matrix[7] = w.y / length;
  tr_matrix[8] = w.z / length;
  return (tr_matrix);
}