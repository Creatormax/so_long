/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:52:36 by hmorales          #+#    #+#             */
/*   Updated: 2022/10/05 10:50:47 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_win *win)
{
	if (collider(win, win->player_x, win->player_y - 1) == 1)
	{	
		print_grass(win, win->player_x, win->player_y);
		win->player_y--;
		print_grass(win, win->player_x, win->player_y);
		print_kirby(win);
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
		print_grass(win, win->player_x, win->player_y);
		win->player_y++;
		print_grass(win, win->player_x, win->player_y);
		print_kirby(win);
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
		print_grass(win, win->player_x, win->player_y);
		win->player_x--;
		print_grass(win, win->player_x, win->player_y);
		print_kirby(win);
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
		print_grass(win, win->player_x, win->player_y);
		win->player_x++;
		print_grass(win, win->player_x, win->player_y);
		print_kirby(win);
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
