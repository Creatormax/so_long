/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:14:56 by hmorales          #+#    #+#             */
/*   Updated: 2022/03/17 18:35:14 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	painter2(t_win *win)
{
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

void	curator2(t_win *win)
{
	if (win->matrix[win->y][win->x] == 'E')
	{
		win->img = mlx_xpm_file_to_image(win->mlx_win, "img/exit.xpm", \
		&win->i_width, &win->i_heigh);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, \
		win->x * 32, win->y * 32);
	}
	else if (win->matrix[win->y][win->x] == 'P')
	{
		win->img = mlx_xpm_file_to_image(win->mlx_win, "img/kirby.xpm", \
		&win->i_width, &win->i_heigh);
		win->player_x = win->x;
		win->player_y = win->y;
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, \
		win->x * 32, win->y * 32);
	}
}
