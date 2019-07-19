/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <bharmund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:32:37 by bharmund          #+#    #+#             */
/*   Updated: 2019/07/19 23:09:13 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;
	t_fdf	*fdf;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putstr("need one file\n");
		return (0);
	}
	if (read_file(fd, &map))
		return (0);
	close(fd);
	if (!(fdf = ft_memalloc(sizeof(t_fdf))))
		exit(1);
	if (init_fdf(fdf, map))
		return (0);
	menu(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, user_hook, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, close_win, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
