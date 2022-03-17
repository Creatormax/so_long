/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:35:05 by hmorales          #+#    #+#             */
/*   Updated: 2022/03/17 21:41:17 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	paint(t_win *win)
{	
	if (win->matrix[win->y][win->x] == 'P')
	{
		win->player_x = win->x;
		win->player_y = win->y;
	}
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, \
	win->x * 32, win->y * 32);
}

void	curator(t_win *win)
{
	win->img = mlx_xpm_file_to_image(win->mlx_win, "img/grass.xpm", \
	&win->i_width, &win->i_heigh);
	paint(win);
	if (win->matrix[win->y][win->x] == '1')
		win->img = mlx_xpm_file_to_image(win->mlx_win, "img/tree.xpm", \
		&win->i_width, &win->i_heigh);
	else if (win->matrix[win->y][win->x] == 'C')
		win->img = mlx_xpm_file_to_image(win->mlx_win, "img/metatomato.xpm", \
		&win->i_width, &win->i_heigh);
	else if (win->matrix[win->y][win->x] == 'E')
		win->img = mlx_xpm_file_to_image(win->mlx_win, "img/exit.xpm", \
		&win->i_width, &win->i_heigh);
	else if (win->matrix[win->y][win->x] == 'P')
		win->img = mlx_xpm_file_to_image(win->mlx_win, "img/kirby.xpm", \
		&win->i_width, &win->i_heigh);
	paint(win);
}

void	painter(t_win *win)
{
	win->movements = 0;
	win->x = 0;
	win->y = 0;
	while (win->y < dimensions_y(win->matrix))
	{
		while (win->x < dimensions_x(win->matrix[0], 0))
		{
			curator(win);
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
	mlx_hook(win.mlx_win, 17, 0L, terminator, &win);
	mlx_hook(win.mlx_win, 2, 1L << 0, key_hook, &win);
	mlx_loop(win.mlx);
}
