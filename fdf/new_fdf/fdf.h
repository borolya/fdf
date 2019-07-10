#ifndef FDF_H
# define FDF_H

# include "libft.h"

typedef struct s_point
{
    double x;
    double y;
    double z;
} t_point;

typedef struct s_map
{
    int h;
    int w;
    int	depth_min;
	int	depth_max;
    t_point **crd;
} t_map;



#endif