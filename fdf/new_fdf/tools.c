#include "fdf.h"

t_point from_int_to_double(t_point_int v)
{
    t_point w;

    w.x = (double)v.x;
    w.y = (double)v.y;
    w.z = (double)v.z;
    return (w);
}

void print_point(t_point v)
{
  printf("x=%lf y = %lf z = %lf\n", v.x, v.y, v.z);
}

t_point vector_min(t_point u, t_point v)
{
  t_point w;

  w.x = u.x - v.x;
  w.y = u.y - v.y;
  w.z = u.z - v.z;
   return (w);
}

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
  w.y = - u.x*v.z + u.z*v.x;
  w.z = u.x*v.y - u.y*v.x;
  return (w);
}

t_point matrix_dot_vector(double *matrix, t_point v)
{
  t_point w;

  w.x = v.x * matrix[0] + v.y * matrix[1] + v.z * matrix[2];
  w.y = v.x * matrix[3] + v.y * matrix[4] + v.z * matrix[5];
  w.z = v.x * matrix[6] + v.y * matrix[7] + v.z * matrix[8];
  return (w); 
}