#ifndef FDF_H
# define FDF_H
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

int sgn(int x);
void draw_line(int x0, int x1, int y0, int y1, int size_x, int size_y, char *img);
void print_matrix(int **matrix, int max_y, int max_x);
int **creat_matrix(t_list **alst, int max_y);
int *take_int(char *line, int *max_x);
int **read_file(int fd, t_point *size_map);
void draw_map(t_dis_point* coord, t_point s, char *img);
t_point vector_sum(t_point u, t_point v);
t_point const_dot_vector(double a, t_point v);
double vector_length(t_point v);
t_point vector_product(t_point u, t_point v);
t_point matrix_dot_vector(double *matrix, t_point v);
void initialization(t_point size_map, t_point *eye, t_point *lookAt, t_point *up, double *N);
t_point from_world_to_aligned(double *tr_matrix, int **matrix, t_point eye, t_point size_map, int i, int j);
t_dis_point *from_world_to_display(double N, int  **matrix, t_point size_map, double *tr_matrix, t_point eye);
double *create_Transformation_matrix(t_point eye, t_point lookAt, t_point up);

# ifndef EYE
#  define EYE 30
# endif

#endif
