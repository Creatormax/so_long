/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:35:05 by hmorales          #+#    #+#             */
/*   Updated: 2022/10/05 12:47:06 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	curator(t_win *win)
{
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
}

t_img	img_loader(t_win *win)
{
	t_img	i;
	int		temp;


	i.tree = mlx_xpm_file_to_image(win->mlx_win, "img/tree.xpm", \
	&temp, &temp);
	i.kirby = mlx_xpm_file_to_image(win->mlx_win, "img/kirby.xpm", \
	&temp, &temp);
	i.exit = mlx_xpm_file_to_image(win->mlx_win, "img/exit.xpm", \
	&temp, &temp);
	i.metatomato = mlx_xpm_file_to_image(win->mlx_win, "img/metatomato.xpm", \
	&temp, &temp);
	i.grass = mlx_xpm_file_to_image(win->mlx_win, "img/grass.xpm", \
	&temp, &temp);
	return (i);
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

	if (!map || map < 0 || map > 256)
		error_msgr("Map: Map does not exist");
	map_arranger(map, &win);
	if (ft_strlen(win.matrix[0]) > 81 || dimensions_y(win.matrix) > 41)
		error_msgr("Where are you going??? That's bigger than the screen!!!");
	coin_counter(&win);
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, dimensions_x(win.matrix[0], 0) * 32, \
	dimensions_y(win.matrix) * 32, "so_long");
	win.image = img_loader(&win);
	painter(&win);
	mlx_hook(win.mlx_win, 17, 0L, terminator, &win);
	mlx_hook(win.mlx_win, 2, 1L << 0, key_hook, &win);
	mlx_loop(win.mlx);
}
