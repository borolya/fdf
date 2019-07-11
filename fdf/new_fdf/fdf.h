#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

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

int read_file(int fd, t_map **map);
int iteration_list(t_list **start, t_map *map);
int take_coord(char *line, t_map *map, int numb);
int word_count(char **split);
int del_list_map(t_list **start, t_map **map, int flag);
void del_start_of_list(t_list **start);

#endif