#include "fdf.h"

void print_matrix(int **matrix, int max_y, int max_x)
{
	int i;
	int j;

	i = 0;
	while (i < max_y)
	{
			j = 0;
			{
				while (j < max_x)
				{
						printf("%d ", matrix[i][j]);
						j++;
				}
				printf("\n");
			}
			i++;
	}
}

int **creat_matrix(t_list **alst, int max_y)
{
	int **matrix;
	t_list *tmp;

	tmp = *alst;
	matrix = (int**)malloc(sizeof(int*) * (max_y));
	while (max_y > 0)
	{
		matrix[max_y - 1] = tmp->content;
		tmp =  tmp->next ;
		max_y--;
	}
	//ftree lst(start)
	return (matrix);
}

//ВСЕ ФРИШИТЬ
int *take_int(char *line, int *max_x)
{
		char **split;
		int *array;
		int i;

		i = 0;
		split = ft_strsplit(line, ' ');//проверка ВАЛИДНОСТИ?
		while (split[i])
			i++;
		array = (int*)ft_memalloc(i*4);
		*max_x = i;
		i = 0;
		while (i < *max_x)
		{
			array[i] = ft_atoi(split[i]);//проверка что число?
			i++;
		}
		return (array);
}

int find_max_z(int **matrix, int max_y, int max_x)
{
	int i;
	int j;
	int z;

	i = 0;
	z = 0;
	while (i < max_y)
	{
        j = 0;
		while(j < max_x)
		{
			if (abs(matrix[i][j]) > abs(z))
				z = abs(matrix[i][j]);
			j++;
		}
		i++;
	}
	return(z);
}

int **read_file(int fd, t_point_int *size_map)
{
	char *line;
	t_list *start;
	int max_x;
	int **matrix;
	
	start = NULL;
	size_map->y = 0;
	if (get_next_line(fd, &line) == 1)
	{
			ft_lstadd(&start, ft_lstnew(take_int(line, &(size_map->x)), (size_map->x)*sizeof(int)));
			(size_map->y)++;
	}
	while (get_next_line(fd, &line) == 1)
	{
				ft_lstadd(&start, ft_lstnew(take_int(line, &max_x), (size_map->x)*sizeof(int)));
				//if ( max_x != size_map->x)
				//	error;
				(size_map->y)++;
	}
 	matrix = creat_matrix(&start, size_map->y);
	print_matrix(matrix, size_map->y, size_map->x);
	size_map->z = find_max_z(matrix, size_map->y, size_map->x);
	print_point(from_int_to_double(*size_map));
    return (matrix);
}