/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:28:35 by hmorales          #+#    #+#             */
/*   Updated: 2022/12/14 12:13:37 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/libft.h"

typedef struct s_sprites
{
	void	*kirby;
	void	*meta;
	void	*tree;
	void	*grass;
	void	*exit;
}	t_sprites;

typedef struct s_win
{
	void		*mlx;
	void		*mlx_win;
	int			x;
	int			y;
	int			dimension_x;
	int			dimension_y;
	int			player_x;
	int			player_y;
	int			coins;
	int			t_coins;
	int			i_heigh;
	int			i_width;
	char		**matrix;
	int			movements;
	t_sprites	sprites;
}	t_win;

int		main(int argc, char **argv);
void	map_arranger(int map, t_win *win);
void	map_render(int map);
int		dimensions_x(char *aux, int j);
int		dimensions_y(char **matrix);
char	*gnl_no_lb(int map);
void	matrix_printer(char **matrix);
void	error_msgr(char *str);
void	up(t_win *win);
void	down(t_win *win);
void	left(t_win *win);
void	right(t_win *win);
int		key_hook(int keycode, t_win *win);
int		terminator(int keycode, void *win);
int		collider(t_win *win, int ny, int nx);
void	coin_counter(t_win *win);
void	ft_free_matrix(char **str);
void	parse_check(char **matrix, int i, int j);
void	print_exit(t_win *win);
void	print_kirby(t_win *win);
void	print_metatomato(t_win *win);
void	print_grass(t_win *win, int x, int y);
void	print_tree(t_win *win);
void	painter(t_win *win);
int		process(t_win win);
void	console_esthetics(t_win win);
char **matrix_zero(int i, int j, t_win win, char** aux);

#endif