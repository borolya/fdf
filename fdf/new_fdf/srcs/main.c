#include "fdf.h"

#include <stdio.h>

void print_map(t_map map)
{
    int i;
    int j;

    printf("h = %d\n w = %d,\n max_z = %d \n min_z = %d\n", map.h, map.w, map.depth_max, map.depth_min);
    i = 0;
    while(i < map.h)
    {
        j = 0;
        while(j < map.w)
        {
            printf(" %d ", (int)map.crd[i][j].z);
            j++;
        }
        printf("\n");
        i++;
    }
}


int main(int argc, char **argv)
{
    t_map *map;
    int fd;
    t_fdf *fdf;

    if(argc != 2)
    {
        ft_putstr("need file\n");
        return (0);
    }
    if ((fd = open(argv[1], O_RDONLY)) < 0 || read_file(fd, &map))
     return (0);
     close(fd);
    if (init_fdf(&fdf, map))
    return (0);
    mlx_hook(fdf->win_ptr, 2, 0, user_hook, fdf);
    mlx_hook(fdf->win_ptr, 17, 0, close_win, fdf);
    mlx_loop (fdf->mlx_ptr);
    return (0);
}