#include "fdf.h"
//or return t_map

int word_count(char **split)
{
    int i;

    i = 0;
    while (split[i])
        i++;
    return (i);
}


int *take_coord(char ***split, int map_w)
{
    double *coord;
    int i;

    if (!(coord = ft_memalloc(sizeof(double) * map->w)))
        //free split, free map, free map ->crd, free start
        rerurn (NULL);    
    while(i < map_w)
    {
        coor[i] = ft_atoi(split[i]);
        i++;
    }
    //free_split
    return (coord);
}

//retrun number of need_free
//-1  = free start; 0 = start, map, map->crd; N>0 -||- + map-<crd[N] 
int take_world_coord(t_list **start, t_map *map)
{
    char **split;
    t_list *tmp;
    int i;
    int max_x;

    if (!(split = ft_strsplit(start->content, ' '))
        //free map, start
    map->w = word_count(split);
    if (!(map->crd[map->h] = take_coord(split, map)))
       return (0);
    tmp = *start->next;
        //free lst_list(start)
    *start = tmp;
    i = map->h - 1;
    while (start != NULL)
    {
        if (!(split = ft_split(start->content, ' '))
            //free start, map, //of end to map->crd[ i ];
        if (map->w != world_count(split))
        {
            //"short length "
            //free map, start, map->crd
        }
        if (!(map->crd[map->h] = take_coord(split, map->w)))
            return (0);
        tmp = *start->next;
        //free lst_list(start)
        *start = tmp;
        i--;
    }
    return (-1);
}


int read_file(int fd, t_map *map)
{
    //mb malloc map
    t_list *start;
    t_list *tmp;
    char *line;
        
    map->h = 0;
    start = NULL;
    while (get_next_line(fd, &line) == 1)
    {
        if (!(tmp = ft_lstnew(line, ft_strlen(line) + 1)))
            //free (start) , free ( map)
        ft_lstadd(&start, tmp);
        free(line);
        map->h++;
    }
    //if map->h = 0 "file is empty"
    if (!(map->crd = ft_memalloc(sizeof(*double) * map->h))
        //free map, 
    if (take_map_coord(&start, map) != 0)
        ft_lstdel(&start, free);
}