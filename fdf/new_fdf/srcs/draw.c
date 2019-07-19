/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:30:34 by bharmund          #+#    #+#             */
/*   Updated: 2019/07/19 21:31:49 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line(dis_point p1, dis_point p2, t_img *img)
{
    dis_point delta;
    dis_point error;
    dis_point sign_d;

    p1.x = p1.x + img->w/2;
    p1.y = p1.y + img->h/2;
    p2.x = p2.x + img->w/2;
    p2.y = p2.y + img->h/2;
    delta.x = abs(p2.x - p1.x);
    delta.y = abs(p2.y - p1.y);
    sign_d.x = p1.x < p2.x ? 1 : -1;
    sign_d.y = p1.y < p2.y ? 1 : -1;
    error.x = delta.x - delta.y;
    if (p2.y >= 0 && p2.y < img->h && p2.x>=0 && p2.x < img->w)
        img->data[p2.y * img->h + p2.x] = 10000;
    while (p1.x != p2.x || p1.y != p2.y)
    {
       if (p1.y >= 0 && p1.y < img->h && p1.x >=0 && p1.x  < img->w)
            img->data[(p1.y ) * img->h + (p1.x)] = 10000;
        if ((error.y = error.x * 2) > - delta.y)   
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

int neqal_dis_point(dis_point p, dis_point q)
{
    if (p.x == q.x && p.y == q.y)
        return (0);
    return (1);
}

void draw_map(dis_point **crd, t_map map, t_img *img)
{
	int i;
	int j;
    dis_point bad;

    bad.x = 1000000;
    bad.y = 1000000;
	i = -1;
	while (++i < map.h)
	{
		j = -1;
		while (++j < map.w)
		{	
            if (neqal_dis_point(crd[i][j], bad))
            {
			    if (i != 0 && neqal_dis_point(crd[i - 1][j], bad)) 
				    draw_line(crd[i][j], crd[i - 1][j], img);
			    if (i != map.h - 1 && neqal_dis_point(crd[i + 1][j], bad))
				    draw_line(crd[i][j], crd[i + 1][j], img);
			    if (j != 0 && neqal_dis_point(crd[i][j - 1], bad)) 
				    draw_line(crd[i][j], crd[i][j - 1], img);
			    if (j != map.w - 1 && neqal_dis_point(crd[i][j + 1], bad))
				    draw_line(crd[i][j], crd[i][j + 1], img);
            }
		}
	}
}
