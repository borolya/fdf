/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:33:31 by bharmund          #+#    #+#             */
/*   Updated: 2019/07/19 21:35:30 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

dis_point projection(t_point point, int projection_flag)
{
    dis_point dis;

    if (projection_flag == 1)
    {
        if (point.z < 0.00000001)
        {
            dis.x = 1000000;
            dis.y = 1000000;
        }
        else
        {
            dis.x =  (int)(400 * point.x / point.z); 
            dis.y =  (int)(400 * point.y / point.z);
        }
    }
    else if (projection_flag == 0)
    {
        dis.x = (int) 15 * point.x;
        dis.y = (int) 15 * point.y;
    }
    else 
    {
        dis.x = (int) 10 *(( point.x - point.y) * cos(0.523599));
        dis.y = (int) 10 * (- point.z + (point.x + point.y) * sin(0.523599));
    }
    return (dis);
}
