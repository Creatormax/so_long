/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:14:56 by hmorales          #+#    #+#             */
/*   Updated: 2022/03/17 21:13:57 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	paint_grass(t_win *win, int x, int y)
{
	win->img = mlx_xpm_file_to_image(win->mlx_win, "img/grass.xpm", \
	&win->i_width, &win->i_heigh);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, \
	x * 32, y * 32);
}

void	paint_kirby(t_win *win, int x, int y)
{
	win->img = mlx_xpm_file_to_image(win->mlx_win, "img/kirby.xpm", \
	&win->i_width, &win->i_heigh);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, \
	x * 32, y * 32);
}

void	paint_metatomato(t_win *win, int x, int y)
{
	win->img = mlx_xpm_file_to_image(win->mlx_win, "img/metatomato.xpm", \
	&win->i_width, &win->i_heigh);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, \
	x * 32, y * 32);
}

void	paint_exit(t_win *win, int x, int y)
{
	win->img = mlx_xpm_file_to_image(win->mlx_win, "img/exit.xpm", \
	&win->i_width, &win->i_heigh);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, \
	x * 32, y * 32);
}

int	dimensions_y(char **matrix)
{
	int	j;

	j = 0;
	while (matrix[j])
		j++;
	return (j);
}
