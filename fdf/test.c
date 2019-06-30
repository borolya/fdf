#include <unistd.h>
#include "mlx.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}

int deal_key(int key, void *param)
{
	ft_putchar('x');
	//mlx_pixel_put(mlx_ptr,win_ptr, 250, 250, 0xFFFFFF);
	return (0);
}
int sgn(int x)
{
	if (x > 0)
		return (1);
	if (x < 0)
			return (-1);
	else
		return (0);
}

char *draw_line(int x0, int x1, int y0, int y1, int size_x, int size_y)
{
	int dx;
	int dy;
	int error;
	int sign_dx;
	int sign_dy;
	char *img;

	img = ft_memalloc(size_x*size_y*4*4);
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
	return (img);
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
		array = ft_memmalloc((i + 1)*4);
		*max_x = i;
		i = 0;
		while (i < max_x)
		{
			array[i] = ft_atoi(split[i]);//проверка что число?
			i++;
		}
		array[i] = NULL;
		return (array);
}


void read(int fd)
{
	char *line;
	t_list *tmp;
	t_list *start;
	int max_y;
	int max_x;
	int tmp;
	int **matrix;
	start == NULL;

	max_y = 0;
	max_x = 0;
	while (get_next_line(fd, &line) == 1)
	{
				ft_lstadd(&start, ft_lstnew(take_int(line, &tmp), max_x*sizeof(int)));
				// if max_x меняется
				max_y++;
	}

	matrix = creat_matrix(*start, max_y, max_x);
}

int *creat_matrix(t_list **alst, int y, int x)
{
	int **matrix;
	int i;
	t_list tmp;

	tmp = *alst;
	matrix = (*int)malloc(sizeof(*int) * max_y);
	i = 0;
	while (i < max_y)
	{
		matrix[i] = tmp->content;
		tmp =  tmp->next ;
		i++;
	}
	//ftree lst(start)
	return (matrix);
}




int main ()
{
	void *mlx_ptr;
	void *win_ptr;
	int bpp;
	int size_line;
	int endian;
	void *img_ptr;
	char *img_data;
	int i;
	char *line;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "HELP");
	img_ptr = mlx_new_image(mlx_ptr, 500, 500);
	img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	ft_memcpy(img_data, draw_line(0, 14, 500, 0, 500, 500), 500*500*4*4);
//	ft_strcpy(img_data, draw_line(0, 150, 0, 100, 500, 500));
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);

	mlx_loop(mlx_ptr);
return (0);
}
