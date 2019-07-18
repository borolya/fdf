#include "fdf.h"

#include <stdio.h>
dis_point min_crd(dis_point **crd, t_map map)
{
    int i;
    int j;
    dis_point move;

    move = crd[0][0];
    i = 0;
    while (i < map.h)
    {
        j = 0;
        while (j < map.w)
        {
            if (crd[i][j].x < move.x)
                move.x = crd[i][j].x;
            if (crd[i][j].y > move.y)
                move.y = crd[i][j].y;
            j++;
        }
        i++;
    }
    return (move);
}

void draw_line(dis_point p1, dis_point p2, dis_point move, t_img *img)
{
    dis_point delta;
    dis_point error;
    dis_point sign_d;
    int pix;

    move.y -= img->h;
    p1.x = p1.x + img->w/2;
    p1.y = p1.y + img->h/2;
    p2.x = p2.x + img->w/2;
    p2.y = p2.y + img->h/2;
    delta.x = abs(p2.x - p1.x);
    delta.y = abs(p2.y - p1.y);
    sign_d.x = p1.x < p2.x ? 1 : -1;
    sign_d.y = p1.y < p2.y ? 1 : -1;
    error.x = delta.x - delta.y;
   // if ((p2.y - move.y)* img->h + (p2.x - move.x) >= 0 && (p2.y - move.y)* img->h + (p2.x - move.x) < img->h * img->w)
    if (p2.y >= 0 && p2.y < img->h && p2.x>=0 && p2.x < img->w)
        img->data[p2.y * img->h + p2.x] = 10000;
    while (p1.x != p2.x || p1.y != p2.y)
    {
        pix = (p1.y ) * img->h + (p1.x);
       // printf("pix = %d ", pix);
       //if (pix >= 0 && pix < img->h * img->w)
       if (p1.y >= 0 && p1.y < img->h && p1.x >=0 && p1.x  < img->w)
            img->data[pix] = 10000;
        error.y = error.x * 2;
        if (error.y > - delta.y)   
        {
            error.x -= delta.y;
            p1.x +=sign_d.x;
        }
        if (error.y < delta.x)
        {
            error.x +=delta.x;
            p1.y +=sign_d.y;
        }
    }
}

void draw_map(dis_point **crd, t_map map, t_img *img)
{
	int i;
	int j;
    dis_point move;

    move = min_crd(crd, map);
//	printf("hi");
	i = 0;
	while (i < map.h)
	{
		j = 0;
		while (j < map.w)
		{	
		//	printf("draw map:i = %d j = %d", i, j);
			if (i != 0) 
				draw_line(crd[i][j], crd[i - 1][j], move, img);
			if (i != map.h - 1)
				draw_line(crd[i][j], crd[i + 1][j], move, img);
			if (j != 0) 
				draw_line(crd[i][j], crd[i][j - 1], move, img);
			if (j != map.w - 1)
				draw_line(crd[i][j], crd[i][j + 1], move, img);
			j++;
		}
		i++;
	}
}