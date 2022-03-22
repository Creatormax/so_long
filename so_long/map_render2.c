/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:14:56 by hmorales          #+#    #+#             */
/*   Updated: 2022/03/22 11:13:18 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	paint_grass(t_win *win, int x, int y)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->grass, \
	x * 32, y * 32);
}

void	paint_kirby(t_win *win, int x, int y)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->kirby, \
	x * 32, y * 32);
}

void	paint_metatomato(t_win *win, int x, int y)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->metatomato, \
	x * 32, y * 32);
}

void	paint_exit(t_win *win, int x, int y)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->exit, \
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
