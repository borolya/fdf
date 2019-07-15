#include "fdf.h"


void perspective(t_map *map, t_point **al_crd, t_point **dis_crd)
{
    ///int_t_point **dis_crd;
    //ранее заммолочены
    int i;
    int j;
    double N;

    //init mb camera and eye
    N = 10;
    i = 0;
    while (i < map->h)
    {
        j = 0;
        while(j < map->w)
        {
            if (al_crd[i][j].z < 0.000001)
            {
                dis_crd[i][j].x = 10000;
                dis_crd[i][j].y = 10000;
                dis_crd[i][j].z = 10000;
            }
            dis_crd[i][j].x = (int)(N * al_crd[i][j].x / al_crd[i][j].z); 
            dis_crd[i][j].y = (int)(N * al_crd[i][j].y / al_crd[i][j].z); 
            j++;
        }
        i++;
    }
}



void parall(t_map *map, t_point **al_crd, t_point **dis_crd);
{
    int i;
    int j;

    i = 0;
    while (i < map->h)
    {
        j = 0;
        while (j < map->w)
        {
            dis_crd[i][j].x = (int)al_crd[i][j].x;
            dis_crd[i][j].y = (int)al_crd[i][j].y;
            j++;
        }
        i++;
    }
}