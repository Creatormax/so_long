/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:35:05 by hmorales          #+#    #+#             */
/*   Updated: 2022/03/17 18:37:05 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dimensions_y(char **matrix)
{
	int	j;

	j = 0;
	while (matrix[j])
		j++;
	return (j);
}

void	curator(t_win *win)
{
	if (win->matrix[win->y][win->x] == '1')
	{
		win->img = mlx_xpm_file_to_image(win->mlx_win, "img/tree.xpm", \
		&win->i_width, &win->i_heigh);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, \
		win->x * 32, win->y * 32);
	}
	else if (win->matrix[win->y][win->x] == 'C')
	{
		win->img = mlx_xpm_file_to_image(win->mlx_win, \
		"img/metatomato.xpm", &win->i_width, &win->i_heigh);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, \
		win->x * 32, win->y * 32);
	}
	else
		curator2(win);
}

void	painter(t_win *win)
{
	win->movements = 0;
	win->x = 0;
	win->y = 0;
	win->img = mlx_xpm_file_to_image(win->mlx_win, "img/grass.xpm", \
	&win->i_width, &win->i_heigh);
	while (win->y < dimensions_y(win->matrix))
	{
		while (win->x < dimensions_x(win->matrix[0], 0))
		{
			mlx_put_image_to_window(win->mlx, win->mlx_win, \
			win->img, win->x * 32, win->y * 32);
			win->x++;
		}
		win->x = 0;
		win->y++;
	}
}

void	map_render(int map)
{
	t_win	win;

	map_arranger(map, &win);
	coin_counter(&win);
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, dimensions_x(win.matrix[0], 0) * 32 \
	, dimensions_y(win.matrix) * 32, "so_long");
	painter(&win);
	painter2(&win);
	mlx_hook(win.mlx_win, 17, 0L, terminator, &win);
	mlx_hook(win.mlx_win, 2, 1L << 0, key_hook, &win);
	mlx_loop(win.mlx);
}
