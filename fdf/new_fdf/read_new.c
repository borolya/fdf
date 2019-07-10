#include "fdf.h"

void del(t_list **start, t_map **map, int flag)
{
    t_list		*tmp;
    int i;

	//if (!alst)
	//	return ;
	while (*start)
	{
		tmp = (*start)->next;
		ft_memdel(&(*start->content));
        ft_memdel(start);
		*start = tmp;
	}
	//*start = NULL;
    if (*map && map)
    {
        i = *map->h;
    //if (flag >= 0)
        while (--i >= flag)
           ft_memdel(&(*map->crd[i]);
        if (flag != -2)
            ft_memdel(&(*map->crd));
        ft_memdel(map));
    }
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
        //free
    map->w = word_count(split);
    if (!(map->crd[numb] = ft_memalloc(sizeof(double) * map -> w)))
        //free
    i = 0;
    while (i < map->w)
    {
        map->crd[numb][i] = fr_atoi(split[i]);
        if (map->crd[numb][i] > map->depth_max)
            map->depth_max = map->crd[numb][i];
        if (map->crd[numb][i] < map->depth_min)
            map->depth_min = map->crd[numb][i];
        i++;
    }
    while (--i >= 0)
        ft_memdel(&split[i]);
    ft_memdel(&split);
}

int iteration_list(t_list **start, t_map *map)
{
    t_list *tmp;
    int max_x;
    int numb;

    map->depth_min = 0;
    map->depth_max = 0;
    numb = map->h - 1;
    if (!take_blabla(*start->content, map, numb))
        //free
    max_x = map->w;
    tmp = *start->next;
        //free_lst
    *start = tmp;
    while (--numd >= 0)//or numb >=0
    {
        if (!take_blabla(*start->content, map, numb))
            //free
        if (max_x != map->x)
        {
             //"short length "
            //free map, start, map->crd
        }
        tmp = *start->next;
        //free_lst
        *start = tmp;
    }
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