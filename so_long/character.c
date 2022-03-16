/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:41:18 by hmorales          #+#    #+#             */
/*   Updated: 2022/03/03 18:49:14 by hmorales         ###   ########.fr       */
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
	ft_putnbr_fd(win->t_coins, 1);
}

int	collider(t_win ***win, int nx, int ny)
{
	if ((**win)->matrix[ny][nx] == '1')
		return (0);
	else if ((**win)->matrix[ny][nx] == 'C')
	{
		(**win)->matrix[ny][nx] = '0';
		(**win)->coins++;
	}
	else if ((**win)->matrix[ny][nx] == 'E' && (**win)->t_coins > \
	(**win)->coins)
		return (0);
	else if ((**win)->matrix[ny][nx] == 'E' && (**win)->t_coins <= \
	(**win)->coins)
	{
		write(1, "YOU WIN", 7);
		write(1, "\n", 1);
		terminator(0, *win);
	}
	return (1);
}

int	key_hook(int keycode, void *win)
{
	t_win	*lol;

	lol = (t_win *)win;
	if (keycode == 53)
	{
		mlx_destroy_window(lol->mlx, lol->mlx_win);
		destroy(&lol);
		exit (0);
	}
	if (keycode == 13 || keycode == 126)
		up(&lol);
	if (keycode == 1 || keycode == 125)
		down(&lol);
	if (keycode == 0 || keycode == 123)
		left(&lol);
	if (keycode == 2 || keycode == 124)
		right(&lol);
	return (0);
}

void	destroy(t_win **win)
{
	int	j;

	j = 0;
	while ((*win)->matrix[j])
		free((*win)->matrix[j++]);
	free((*win)->matrix);
}
