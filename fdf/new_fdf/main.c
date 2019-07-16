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
    t_scene *scene;
    t_fdf *fdf;

    if(argc != 2)
    {
        ft_putstr("need file\n");
        return (0);
    }
    if ((fd = open(argv[1], O_RDONLY)) < 0 || read_file(fd, &map))
     return (0);
    /*
    fd = open(argv[1], O_RDONLY);
    printf("fd = %d\n", fd);
    if (fd < 0)
        return (0); 
    if (read_file(fd, &map))
        return (0);
    print_map(*map);
    */
   //print_map(*map);
   if (init_fdf(&fdf, map))
    return (0);
    //mlx_hook(win_ptr, 2, 0, user_hook, fgf);

    mlx_loop (fdf->mlx_ptr);
    return (0);
}