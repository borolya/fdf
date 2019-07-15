#include "fdf.h"

t_point take_al_coord(double *tr_matrix, t_point point, t_scene *scene)
{
   return(matrix_dot_vector(tr_matrix, vector_min(point,scene->eye)));
}
//can connect this
dis_point projection(t_point point, int projection_flag)
{
    dis_point dis;
    if (projection_flag == 1)
    {
        if (point.z < 0.000001)
        {
            dis.x = 10000;
            dis.y = 10000;
        }
        dis.x = (int)(point.x / point.z); 
        dis.y = (int)(point.y / point.z);
    }
    else 
    {
        dis.x = (int)point.x;
        dis.y = (int)point.y;
    }
    return (dis);
}
