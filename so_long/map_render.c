/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:35:05 by hmorales          #+#    #+#             */
/*   Updated: 2022/11/23 15:48:08 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_win *win)
{
	win->sprites.kirby = mlx_xpm_file_to_image(win->mlx, "img/kirby.xpm", \
	&win->i_width, &win->i_heigh);
	win->sprites.exit = mlx_xpm_file_to_image(win->mlx, "img/exit.xpm", \
	&win->i_width, &win->i_heigh);
	win->sprites.meta = mlx_xpm_file_to_image(win->mlx, "img/metatomato.xpm", \
	&win->i_width, &win->i_heigh);
	win->sprites.tree = mlx_xpm_file_to_image(win->mlx, "img/tree.xpm", \
	&win->i_width, &win->i_heigh);
	win->sprites.grass = mlx_xpm_file_to_image(win->mlx, "img/grass.xpm", \
	&win->i_width, &win->i_heigh);
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
			print_grass(win, win->x, win->y);
			if (win->matrix[win->y][win->x] == '1')
				print_tree(win);
			else if (win->matrix[win->y][win->x] == 'C')
				print_metatomato(win);
			else if (win->matrix[win->y][win->x] == 'E')
				print_exit(win);
			else if (win->matrix[win->y][win->x] == 'P')
			{
				win->player_x = win->x;
				win->player_y = win->y;
				print_kirby(win);
			}
					win->x++;
		}
		win->x = 0;
		win->y++;
	}
}

void	map_render(int map)
{
	t_win	win;
	int		i;

	i = 0;
	ft_bzero(&win, sizeof(win));
	if (!map || map < 0 || map > 256)
		error_msgr("Map: Map does not exist");
	map_arranger(map, &win);
	if (ft_strlen(win.matrix[0]) > 81 || dimensions_y(win.matrix) > 41)
		error_msgr("Where are you going??? That's bigger than the screen!!!");
	i = process(win);
	if (i != 0)
	{
		printf("\n%d\n", i);
		error_msgr("There is no valid path");
	}
	coin_counter(&win);
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, dimensions_x(win.matrix[0], 0) * 32, \
	dimensions_y(win.matrix) * 32, "so_long");
	load_sprites(&win);
	painter(&win);
	mlx_hook(win.mlx_win, 17, 0L, terminator, &win);
	mlx_hook(win.mlx_win, 2, 1L << 0, key_hook, &win);
	mlx_loop(win.mlx);
}
