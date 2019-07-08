#include "fdf.h"

void all_red(int x, int y, char *data)
{
    int i;
    int j;

    i = 0;
    while(i < y)
    {
        j = 0;
        while(j < x)
        {
            data[i * x * 4 + j * 4 + 2] = (char)200;
            j++;
        }
    i++;
    } 
}



int main(int argc, char **argv)
{
    t_point_int size_map;
    int **matrix;
    t_point eye;
    t_point lookAt;
    t_point up;
    double N;
    t_dis_point *dis_coord;
    double *tr_matrix;

    void *mlx_ptr;
    void *mlx_win;
    void *img;
    char *img_data;
    int win_width;
    int win_height;
    //int img_width;
    //int img_height;
    int bits_per_pixel;
    int size_line;
    int endian;

    int i;
    int j;


    if (argc != 2)
    {
        ft_putstr("need correct data\n");
        return (0);
    }
    matrix = read_file(open(argv[1], O_RDONLY), &size_map);
    initialization(from_int_to_double(size_map), &eye, &lookAt, &up, &N);
    tr_matrix = create_Transformation_matrix(eye, lookAt, up);
    dis_coord = from_world_to_display(N, matrix, (from_int_to_double(size_map)), tr_matrix, eye);
   /* dis_coord = ft_memalloc(sizeof(t_dis_point) * size_map.x * size_map.y);
    i = 0;
    while ( i < size_map.y)
    {
        j = 0;
        while( j < size_map.x)
        {
            (dis_coord[i * (int)size_map.x + j]).x = j * 10;
            (dis_coord[i * (int)size_map.x + j]).y = i * 10;
            j++;
        }
        i++;
    }
    */
   printf("hu");
    mlx_ptr = mlx_init();
    win_height = 500;
    win_width = 500;
    mlx_win = mlx_new_window(mlx_ptr, win_width, win_height, "fdf");
    
    img = mlx_new_image (mlx_ptr, img_width, img_height);
    img_data = mlx_get_data_addr ( img, &bits_per_pixel, &size_line, &endian);
    //all_red(img_width, img_height, img_data);
   // draw_line(-40, -27, 37, 25, img_width, img_height, img_data);
    draw_map(dis_coord, size_map, img_data);
     mlx_put_image_to_window (mlx_ptr, mlx_win, img, 0, 0);
    mlx_loop ( mlx_ptr );

    return (0);
}
