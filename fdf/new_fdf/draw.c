#include "fdf.h"

dis_point min_crd(dis_point **crd, t_map *map)
{
    int i;
    int j;
    dis_point min;

    min = crd[0][0];
    i = 0;
    while (i < map->h)
    {
        j = 0;
        while (j < map->w)
        {
            if (crd[i][j].x < min.x)
                min.x = crd[i][j].x;
            if (crd[i][j].y < min.y)
                min.y = crd[i][j].y;
            j++;
        }
        i++;
    }
    return (min);
}

void draw_line(dis_point p1, dis_point p2, t_map *map)
{
    dis_point min;
    dis_point delta;
    dis_point error;
    dis_point sign_d;

    delta.x = abs(p1.x - p2.x);
    delta.y = abs(p1.y - p2.y);
    sign_d.x = x0 < x1 ? 1 : -1;

}