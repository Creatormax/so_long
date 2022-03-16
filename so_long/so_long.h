/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:28:35 by hmorales          #+#    #+#             */
/*   Updated: 2022/03/03 18:54:33 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

typedef struct win
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		coins;
	int		t_coins;
	void	*grass;
	void	*kirby;
	void	*tree;
	void	*metatomato;
	void	*exit;
	char	**matrix;
}	t_win;

int		main(int argc, char **argv);
char	**map_arranger(int map);
void	map_render(int map);
int		dimensions_x(char *aux, int j);
int		dimensions_y(char **matrix);
char	*gnl_no_lb(int map);
void	matrix_printer(int j, char **matrix);
void	up(t_win **win);
void	down(t_win **win);
void	left(t_win **win);
void	right(t_win **win);
int		key_hook(int keycode, void *win);
int		terminator(int keycode, void *win);
int		collider(t_win ***win, int ny, int nx);
void	coin_counter(t_win *win);
void	destroy(t_win **win);

#endif