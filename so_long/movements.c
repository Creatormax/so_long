/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:52:36 by hmorales          #+#    #+#             */
/*   Updated: 2022/03/17 18:33:56 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_win *win)
{
	if (collider(win, win->player_x, win->player_y - 1) == 1)
	{	
		win->img = mlx_xpm_file_to_image(win->mlx_win, "img/grass.xpm", \
		&win->i_width, &win->i_heigh);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, \
		win->player_x * 32, win->player_y * 32);
		win->player_y--;
		win->img = mlx_xpm_file_to_image(win->mlx_win, "img/kirby.xpm", \
		&win->i_width, &win->i_heigh);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, \
		win->player_x * 32, win->player_y * 32);
		win->movements++;
		write(1, "Number of movements: ", 21);
		ft_putnbr_fd(win->movements, 1);
		write(1, "\n", 1);
	}
}

void	down(t_win *win)
{
	if (collider(win, win->player_x, win->player_y + 1) == 1)
	{	
		win->img = mlx_xpm_file_to_image(win->mlx_win, "img/grass.xpm", \
		&win->i_width, &win->i_heigh);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, \
		win->player_x * 32, win->player_y * 32);
		win->player_y++;
		win->img = mlx_xpm_file_to_image(win->mlx_win, "img/kirby.xpm", \
		&win->i_width, &win->i_heigh);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, \
		win->player_x * 32, win->player_y * 32);
		win->movements++;
		write(1, "Number of movements: ", 21);
		ft_putnbr_fd(win->movements, 1);
		write(1, "\n", 1);
	}
}

void	left(t_win *win)
{
	if (collider(win, win->player_x - 1, win->player_y) == 1)
	{
		win->img = mlx_xpm_file_to_image(win->mlx_win, "img/grass.xpm", \
		&win->i_width, &win->i_heigh);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, \
		win->player_x * 32, win->player_y * 32);
		win->player_x--;
		win->img = mlx_xpm_file_to_image(win->mlx_win, "img/kirby.xpm", \
		&win->i_width, &win->i_heigh);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, \
		win->player_x * 32, win->player_y * 32);
		win->movements++;
		write(1, "Number of movements: ", 21);
		ft_putnbr_fd(win->movements, 1);
		write(1, "\n", 1);
	}
}

void	right(t_win *win)
{
	if (collider(win, win->player_x + 1, win->player_y) == 1)
	{
		win->img = mlx_xpm_file_to_image(win->mlx_win, "img/grass.xpm", \
		&win->i_width, &win->i_heigh);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, \
		win->player_x * 32, win->player_y * 32);
		win->player_x++;
		win->img = mlx_xpm_file_to_image(win->mlx_win, "img/kirby.xpm", \
		&win->i_width, &win->i_heigh);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, \
		win->player_x * 32, win->player_y * 32);
		win->movements++;
		write(1, "Number of movements: ", 21);
		ft_putnbr_fd(win->movements, 1);
		write(1, "\n", 1);
	}
}

void	ft_free_matrix(char **str)
{
	int	j;

	j = 0;
	while (str[j])
		free(str[j++]);
	free(str);
}
