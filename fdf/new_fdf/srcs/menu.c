/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:32:52 by bharmund          #+#    #+#             */
/*   Updated: 2019/07/19 21:32:55 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void menu(t_fdf *fdf)
{
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, 15, 10000000, "MENU");
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, 35, 100000, "for zoom press + or -");
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, 55, 100000, "for change projection press 0 - parallel,  1 - perspective, 2 iso");
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, 75, 100000, "for X-Axis rotation press R or T");
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, 95, 100000, "for Y-Axis rotation press S or D");
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, 115, 100000, "for Z-Axis rotation press W or E");
}
