/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:35:05 by hmorales          #+#    #+#             */
/*   Updated: 2022/03/03 18:54:20 by hmorales         ###   ########.fr       */
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

void	curator(t_win ***win)
{
	if ((**win)->matrix[(**win)->y][(**win)->x] == '1')
		mlx_put_image_to_window((**win)->mlx, (**win)->mlx_win, (**win)->tree, \
		(**win)->x * 32, (**win)->y * 32);
	else if ((**win)->matrix[(**win)->y][(**win)->x] == 'C')
		mlx_put_image_to_window((**win)->mlx, (**win)->mlx_win, \
		(**win)->metatomato, (**win)->x * 32, (**win)->y * 32);
	else if ((**win)->matrix[(**win)->y][(**win)->x] == 'E')
		mlx_put_image_to_window((**win)->mlx, (**win)->mlx_win, (**win)->exit, \
		(**win)->x * 32, (**win)->y * 32);
	else if ((**win)->matrix[(**win)->y][(**win)->x] == 'P')
	{
		mlx_put_image_to_window((**win)->mlx, (**win)->mlx_win, (**win)->kirby, \
		(**win)->x * 32, (**win)->y * 32);
		(**win)->player_x = (**win)->x;
		(**win)->player_y = (**win)->y;
	}
}

void	painter(t_win **win)
{
	(*win)->x = 0;
	(*win)->y = 0;
	while ((*win)->y < dimensions_y((*win)->matrix))
	{
		while ((*win)->x < dimensions_x((*win)->matrix[0], 0))
		{
			mlx_put_image_to_window((*win)->mlx, (*win)->mlx_win, \
			(*win)->grass, (*win)->x * 32, (*win)->y * 32);
			(*win)->x++;
		}
		(*win)->x = 0;
		(*win)->y++;
	}
	(*win)->x = 0;
	(*win)->y = 0;
	while ((*win)->y < dimensions_y((*win)->matrix))
	{
		while ((*win)->x < dimensions_x((*win)->matrix[0], 0))
		{
			curator(&win);
			(*win)->x++;
		}
		(*win)->x = 0;
		(*win)->y++;
	}
}

void	img_loader(t_win *win)
{
	int		temp;

	win->grass = mlx_xpm_file_to_image(win->mlx_win, "img/grass.xpm", \
	&temp, &temp);
	win->exit = mlx_xpm_file_to_image(win->mlx_win, "img/exit.xpm", \
	&temp, &temp);
	win->kirby = mlx_xpm_file_to_image(win->mlx_win, "img/kirby.xpm", \
	&temp, &temp);
	win->metatomato = mlx_xpm_file_to_image(win->mlx_win, \
	"img/metatomato.xpm", &temp, &temp);
	win->tree = mlx_xpm_file_to_image(win->mlx_win, "img/tree.xpm", \
	&temp, &temp);
	painter(&win);
}

void	map_render(int map)
{
	t_win	win;

	win.matrix = map_arranger(map);
	coin_counter(&win);
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, dimensions_x(win.matrix[0], 0) * 32 \
	, dimensions_y(win.matrix) * 32, "so_long");
	img_loader(&win);
	mlx_hook(win.mlx_win, 17, 0L, terminator, &win);
	mlx_hook(win.mlx_win, 2, 1L << 0, key_hook, &win);
	mlx_loop(win.mlx);
}
