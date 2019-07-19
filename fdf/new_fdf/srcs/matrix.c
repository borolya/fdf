/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:33:16 by bharmund          #+#    #+#             */
/*   Updated: 2019/07/19 21:33:22 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double *transformation_matrix(t_scene *scene)
{
  t_point w;
  t_point u;
  t_point v;
  double length;
  double *tr_matrix;

  if (!(tr_matrix = ft_memalloc(sizeof(double)* 9)))
    exit (1);
  w = vector_min(scene->lookAt, scene->eye);
  v = vector_product(w, scene->up);
  u = vector_product(w, v);
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
