/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:41:18 by hmorales          #+#    #+#             */
/*   Updated: 2022/11/09 12:11:08 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	terminator(int keycode, void *win)
{
	(void)win;
	(void)keycode;
	exit (0);
}

void	coin_counter(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	win->coins = 0;
	win->t_coins = 0;
	while (dimensions_y(win->matrix) > j)
	{
		while (dimensions_x(win->matrix[j], j) > i)
		{
			if (win->matrix[j][i] == 'C')
				win->t_coins++;
			i++;
		}
		i = 0;
		j++;
	}
}

int	collider(t_win *win, int nx, int ny)
{
	if (win->matrix[ny][nx] == '1')
		return (0);
	else if (win->matrix[ny][nx] == 'C')
	{
		win->matrix[ny][nx] = '0';
		win->coins++;
	}
	else if (win->matrix[ny][nx] == 'E' && win->t_coins > \
	win->coins)
		return (0);
	else if (win->matrix[ny][nx] == 'E' && win->t_coins <= \
	win->coins)
	{
		write(1, "YOU WIN", 7);
		write(1, "\n", 1);
		terminator(0, win);
	}
	return (1);
}

int	key_hook(int keycode, t_win *win)
{
	if (keycode == 53)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		ft_free_matrix(win->matrix);
		exit (0);
	}
	if (keycode == 13 || keycode == 126)
		up(win);
	if (keycode == 1 || keycode == 125)
		down(win);
	if (keycode == 0 || keycode == 123)
		left(win);
	if (keycode == 2 || keycode == 124)
		right(win);
	return (0);
}
