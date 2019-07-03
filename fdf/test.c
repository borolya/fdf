#include "fdf.h"

int sgn(int x)
{
	if (x > 0)
		return (1);
	if (x < 0)
			return (-1);
	else
		return (0);
}

void draw_line(int x0, int x1, int y0, int y1, int size_x, int size_y, char *img)
{
	int dx;
	int dy;
	int error;
	int sign_dx;
	int sign_dy;
	//char *img;

//	img = ft_memalloc(size_x*size_y*4*4);
	dx = abs(x0- x1);
	dy = abs(y0 - y1);
	sign_dx = x0 < x1 ? 1 : -1;
	sign_dy = y0 < y1 ? 1 : -1;
	error = dx - dy;
	img[(x1)*4  + (y1)*size_x*4] = (char)255; //-??
	while(x0 != x1 || y0 != y1)
	{
		img[x0*4  + y0*size_x*4] = (char)255;
		if (2*error > -dy)
		{
			error = error - dy;
			x0 = x0 + sign_dx;
		}
		if (2*error < dx)
		{
			error = error + dx;
			y0 = y0 + sign_dy;
		}
	}
	//return (img);
}



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

int **read_file(int fd, t_point *size_map)
{
	char *line;
	t_list *start;
	int max_y;
	int max_x;
	int tmp;
	int **matrix;

	start = NULL;
	max_y = 0;
	max_x = 0;
	if (get_next_line(fd, &line) == 1)
	{
			ft_lstadd(&start, ft_lstnew(take_int(line, &max_x), (max_x)*sizeof(int)));
			max_y++;
	}
	while (get_next_line(fd, &line) == 1)
	{
				ft_lstadd(&start, ft_lstnew(take_int(line, &tmp), (max_x)*sizeof(int)));
				//if (tmp != max_x)
				//	error;
				max_y++;
	}
	size_map->x = max_x;
	size_map->y = max_y;
	size_map->z = 10;
 	matrix = creat_matrix(&start, max_y);
	print_matrix(matrix, max_y, max_x);
	return (matrix);
}

void draw_map(t_dis_point *coord, t_point s, char *img)
{
	int i;
	int j;

	i = 0;
	while (i < s.y)
	{
		j = 0;
		while (j < s.x)
		{	
			if (i != 0) 
				draw_line(coord[i * (int)s.x + j].x, coord[(i - 1)* (int)s.x + j].x, coord[i * (int)s.x + j].y, coord[(i - 1)  * (int)s.x + j].y, s.x, s.y, img);
			if (i != s.y - 1)
				draw_line(coord[i * (int)s.x + j].x, coord[(i + 1)* (int)s.x + j].x, coord[i * (int)s.x + j].y, coord[(i + 1)  * (int)s.x + j].y, s.x, s.y, img);
			if (j != 0)
				draw_line(coord[i * (int)s.x + j].x, coord[i * (int)s.x + j - 1].x, coord[i * (int)s.x + j].y, coord[i * (int)s.x + j - 1].y, s.x, s.y, img);
			if (j != s.x - 1)
				draw_line(coord[i * (int)s.x + j].x, coord[i * (int)s.x + j + 1].x, coord[i * (int)s.x + j].y, coord[i * (int)s.x + j + 1].y, s.x, s.y, img);
			j++;
		}
		i++;
	}
}


