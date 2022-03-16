/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:52:36 by hmorales          #+#    #+#             */
/*   Updated: 2022/03/03 16:29:44 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_win **win)
{
	if (collider(&win, (*win)->player_x, (*win)->player_y - 1) == 1)
	{	
		mlx_put_image_to_window((*win)->mlx, (*win)->mlx_win, (*win)->grass, \
		(*win)->player_x * 32, (*win)->player_y * 32);
		(*win)->player_y--;
		mlx_put_image_to_window((*win)->mlx, (*win)->mlx_win, (*win)->kirby, \
		(*win)->player_x * 32, (*win)->player_y * 32);
	}
	write(1, "X: ", 3);
	ft_putnbr_fd((*win)->player_x, 1);
	write(1, "Y: ", 3);
	ft_putnbr_fd((*win)->player_y, 1);
	write(1, "\n", 1);
}

void	down(t_win **win)
{
	if (collider(&win, (*win)->player_x, (*win)->player_y + 1) == 1)
	{	
		mlx_put_image_to_window((*win)->mlx, (*win)->mlx_win, (*win)->grass, \
		(*win)->player_x * 32, (*win)->player_y * 32);
		(*win)->player_y++;
		mlx_put_image_to_window((*win)->mlx, (*win)->mlx_win, (*win)->kirby, \
		(*win)->player_x * 32, (*win)->player_y * 32);
	}
	write(1, "X: ", 3);
	ft_putnbr_fd((*win)->player_x, 1);
	write(1, "Y: ", 3);
	ft_putnbr_fd((*win)->player_y, 1);
	write(1, "\n", 1);
}

void	left(t_win **win)
{
	if (collider(&win, (*win)->player_x - 1, (*win)->player_y) == 1)
	{
		mlx_put_image_to_window((*win)->mlx, (*win)->mlx_win, (*win)->grass, \
		(*win)->player_x * 32, (*win)->player_y * 32);
		(*win)->player_x--;
		mlx_put_image_to_window((*win)->mlx, (*win)->mlx_win, (*win)->kirby, \
		(*win)->player_x * 32, (*win)->player_y * 32);
	}
	write(1, "X: ", 3);
	ft_putnbr_fd((*win)->player_x, 1);
	write(1, "Y: ", 3);
	ft_putnbr_fd((*win)->player_y, 1);
	write(1, "\n", 1);
}

void	right(t_win **win)
{
	if (collider(&win, (*win)->player_x + 1, (*win)->player_y) == 1)
	{
		mlx_put_image_to_window((*win)->mlx, (*win)->mlx_win, (*win)->grass, \
		(*win)->player_x * 32, (*win)->player_y * 32);
		(*win)->player_x++;
		mlx_put_image_to_window((*win)->mlx, (*win)->mlx_win, (*win)->kirby, \
		(*win)->player_x * 32, (*win)->player_y * 32);
	}
	write(1, "X: ", 3);
	ft_putnbr_fd((*win)->player_x, 1);
	write(1, "Y: ", 3);
	ft_putnbr_fd((*win)->player_y, 1);
	write(1, "\n", 1);
}
