#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_dis_point
{
    int x;
    int y;
}   dis_point;

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

typedef struct s_scene
{
    t_point eye;
    t_point up;
    t_point lookAt;
} t_scene;

typedef struct s_img
{
    void *ptr;
    int *data;
    int w;
    int h;
    int b_p_pixel;
    int s_l;
    int endian;
} t_img;

typedef struct s_fdf
{
    void *mlx_ptr;
    void *win_ptr;
    int win_w;
    int win_h;
    int zoom;
    int projection;
    t_img *img;
    t_scene *scene;
    t_map *map;
} t_fdf;
//read
int read_file(int fd, t_map **map);
int iteration_list(t_list **start, t_map *map);
int take_coord(char *line, t_map *map, int numb);
int word_count(char **split);
int del_list_map(t_list **start, t_map **map, int flag);
void del_start_of_list(t_list **start);
//tools
t_point vector_min(t_point u, t_point v);
t_point vector_sum(t_point u, t_point v);
t_point const_dot_vector(double a, t_point v);
double vector_length(t_point v);
t_point vector_product(t_point u, t_point v);
t_point matrix_dot_vector(double *matrix, t_point v);
//prijection
dis_point projection(t_point point, int projection_flag);
t_point take_al_coord(double *tr_matrix, t_point point, t_scene *scene);
//draw
dis_point min_crd(dis_point **crd, t_map map);
void draw_line(dis_point p1, dis_point p2, dis_point move, t_img *img);
void draw_map(dis_point **crd, t_map map, t_img *img);
//matrix
int transformation_matrix(t_scene *scene, double **tr_matrix);
//fdf
dis_point **take_dis_crd(t_fdf *fdf);
int init_image(void *mlx_ptr, t_img *img);
int init_scene(t_scene *scene, t_map *map, int projection);
int init_fdf(t_fdf **fdf, t_map *map);
#endif