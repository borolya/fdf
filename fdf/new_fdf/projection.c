#include "fdf.h"

#include <stdio.h>

t_point take_al_coord(double *tr_matrix, t_point point, t_scene *scene)
{
   return(matrix_dot_vector(tr_matrix, vector_min(point,scene->eye)));
}
//can connect this
dis_point projection(t_point point, int projection_flag)
{
    int N;

    N = 400;
    dis_point dis;
    if (projection_flag == 1)
    {
        if (point.z < 0.00000001)
        {
            dis.x = 100000;
            dis.y = 100000;
        }
        else
        {
            dis.x =  (int)(N * point.x / point.z); 
            dis.y =  (int)(N * point.y / point.z);
        }
    }
    else 
    {
        dis.x = (int) 15 * point.x;
        dis.y = (int) 15 * point.y;
    }
    return (dis);
}
