#include "fdf.h"

//1 is error
//error del
void del_start_of_list(t_list **start)
{
    t_list *tmp;

    tmp = (*start)->next;
    ft_memdel((void**)&((*start)->content));
    ft_memdel((void**)start);
    *start = tmp;
}

int del_list_map(t_list **start, t_map **map, int flag)
{
    t_list		*tmp;
    int i;

	while (*start && start)
        del_start_of_list(start);
    if (*map && map)
    {
        i = (*map)->h;
        if (flag >= 0)// free from h to flag
        {
            while (--i >= flag)
                ft_memdel((void**)&((*map)->crd[i]));
        }
        if (flag != -2) //if flag == -1 free only map->crd//if flag == -2 free only map
            ft_memdel((void**)&((*map)->crd));
        ft_memdel((void**)map);
    }
    return (1);
 }

int word_count(char **split)
{
    int i;

    i = 0;
    while (split[i])
        i++;
    return (i);
}

int take_coord(char *line, t_map *map, int numb)
{
    char **split;
    int i;

    if (!(split = ft_strsplit(line, ' ')))
        return(1);
    map->w = word_count(split);
    if (!(map->crd[numb] = ft_memalloc(sizeof(t_point) * map->w)))
        return(1);
    i = 0;
    while (i < map->w)
    {
        map->crd[numb][i].x = (double)i;
        map->crd[numb][i].y = (double)numb;
        map->crd[numb][i].z = (double)ft_atoi(split[i]);
        if (map->crd[numb][i].z > map->depth_max)
            map->depth_max = map->crd[numb][i].z;
        if (map->crd[numb][i].z < map->depth_min)
            map->depth_min = map->crd[numb][i].z;
        i++;
    }
    while (--i >= 0)
        ft_memdel((void**)&split[i]);
    ft_memdel((void**)&split);
    return (0);
}

int iteration_list(t_list **start, t_map *map)
{
    t_list *tmp;
    int max_x;
    int numb;

    map->depth_min = 0;
    map->depth_max = 0;
    numb = map->h - 1;
    if (take_coord((*start)->content, map, numb))
        return(del_list_map(start, &map, -1));
    max_x = map->w;
    del_start_of_list(start);
    while (--numb >= 0)
    {
        if (take_coord((*start)->content, map, numb))
            return(del_list_map(start, &map, numb + 1));
        if (max_x != map->w)
        {
            ft_putstr("short length\n");
            return(del_list_map(start, &map, numb));
        }
        del_start_of_list(start);
    }
    return (0);
}

int read_file(int fd, t_map **map)
{
    t_list *start;
    t_list *tmp;
    char *line;
    
    if (!(*map = ft_memalloc(sizeof(t_map))))
        return (1);
    (*map)->h = 0;
    start = NULL;
    while (get_next_line(fd, &line) == 1)
    {
        if (!(tmp = ft_lstnew(line, ft_strlen(line) + 1)))
            return (del_list_map(&start, map, -2));
        ft_lstadd(&start, tmp);
        free(line);
        (*map)->h++;
    }
    if ((*map)->h == 0 || !((*map)->crd = ft_memalloc(sizeof(t_point*) * (*map)->h)))
    {
         ft_putstr("empty file\n");
        return (del_list_map(&start, map, -2));
    }
   // if (!(map->crd = ft_memalloc(sizeof(*double) * map->h))
     //   return (del_li)
    return (iteration_list(&start, *map));
}