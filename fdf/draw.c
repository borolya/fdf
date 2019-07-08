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
	if (((x1)*4  + (y1)*size_x*4) >= 0 && (x1)*4  + (y1)*size_x*4 < size_x * size_y * 4 * 4)
		img[(x1)*4  + (y1)*size_x*4] = (char)255; //-??
	while(x0 != x1 || y0 != y1)
	{
		if (x0 * 4 + y0 * size_x * 4 >= 0 && x0 * 4 + y0 * size_x * 4 < size_x * size_y * 4 * 4)
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


void draw_map(t_dis_point *coord, t_point_int s, char *img)
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
				draw_line(coord[i * (int)s.x + j].x, coord[(i - 1)* (int)s.x + j].x, coord[i * (int)s.x + j].y, coord[(i - 1)  * (int)s.x + j].y, img_width, img_height, img);
			if (i != s.y - 1)
				draw_line(coord[i * (int)s.x + j].x, coord[(i + 1)* (int)s.x + j].x, coord[i * (int)s.x + j].y, coord[(i + 1)  * (int)s.x + j].y, img_width, img_height, img);
			if (j != 0)
				draw_line(coord[i * (int)s.x + j].x, coord[i * (int)s.x + j - 1].x, coord[i * (int)s.x + j].y, coord[i * (int)s.x + j - 1].y, img_width, img_height, img);
			if (j != s.x - 1)
				draw_line(coord[i * (int)s.x + j].x, coord[i * (int)s.x + j + 1].x, coord[i * (int)s.x + j].y, coord[i * (int)s.x + j + 1].y, img_width, img_height, img);
			j++;
		}
		i++;
	}
}


