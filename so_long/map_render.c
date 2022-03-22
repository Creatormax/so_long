/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:35:05 by hmorales          #+#    #+#             */
/*   Updated: 2022/03/22 16:37:42 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	paint_tree(t_win *win, int x, int y)
{	
	win->tree = mlx_xpm_file_to_image(win->mlx_win, "img/tree.xpm", \
	&win->i_width, &win->i_heigh);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->tree, \
	x * 32, y * 32);
}

void	curator(t_win *win)
{
	if (win->matrix[win->y][win->x] == '1')
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->tree, \
		win->x * 32, win->y * 32);
	else if (win->matrix[win->y][win->x] == 'C')
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->metatomato, \
		win->x * 32, win->y * 32);
	else if (win->matrix[win->y][win->x] == 'E')
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->exit, \
		win->x * 32, win->y * 32);
	else if (win->matrix[win->y][win->x] == 'P')
	{
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->kirby, \
		win->x * 32, win->y * 32);
		win->player_x = win->x;
		win->player_y = win->y;
	}
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
			mlx_put_image_to_window(win->mlx, win->mlx_win, win->grass, \
			win->x * 32, win->y * 32);
			curator(win);
			win->x++;
		}
		win->x = 0;
		win->y++;
	}
}

void	img_loader(t_win *win)
{
	win->exit = mlx_xpm_file_to_image(win->mlx_win, "img/exit.xpm", \
	&win->i_width, &win->i_heigh);
	win->metatomato = mlx_xpm_file_to_image(win->mlx_win, "img/metatomato.xpm", \
	&win->i_width, &win->i_heigh);
	win->kirby = mlx_xpm_file_to_image(win->mlx_win, "img/kirby.xpm", \
	&win->i_width, &win->i_heigh);
	win->grass = mlx_xpm_file_to_image(win->mlx_win, "img/grass.xpm", \
	&win->i_width, &win->i_heigh);
	win->tree = mlx_xpm_file_to_image(win->mlx_win, "img/tree.xpm", \
	&win->i_width, &win->i_heigh);
}

void	map_render(int map)
{
	t_win	win;

	if (!map || map < 0 || map > 256)
	{
		write(1, "Map: Map does not exist", 24);
		exit (0);
	}
	map_arranger(map, &win);
	if (ft_strlen(win.matrix[0]) > 81 || dimensions_y(win.matrix) > 41)
	{
		write(1, "Where are you going??? That's bigger than the screen!!!", 56);
		exit (0);
	}
	coin_counter(&win);
	img_loader(&win);
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, dimensions_x(win.matrix[0], 0) * 32 \
	, dimensions_y(win.matrix) * 32, "so_long");
	painter(&win);
	mlx_hook(win.mlx_win, 17, 0L, terminator, &win);
	mlx_hook(win.mlx_win, 2, 1L << 0, key_hook, &win);
	mlx_loop(win.mlx);
}
