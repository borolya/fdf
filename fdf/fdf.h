#ifndef FDF_H
# define FDF_F
# include <unistd.h>
# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>
# include <strings.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>

typedef struct  s_point
{
  double x;
  double y;
  double z;
} t_point;

typedef struct s_dis_point
{
  int x;
  int y;
} t_dis_point;

# ifndef EYE
#  define EYE 500
# endif

#endif
