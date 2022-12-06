/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:27:07 by hmorales          #+#    #+#             */
/*   Updated: 2022/12/06 14:03:30 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dimensions_x(char *aux, int j)
{
	int		i;

	i = 0;
	if (!aux)
		return (j);
	while (aux[i] != '\n' && aux[i] != '\0')
		i++;
	return (i);
}

void	error_msgr(char *str)
{
	write(1, "Error\n", 6);
	write(1, str, dimensions_x(str, 0));
	exit (1);
}

void	map_checker2(char **matrix, int i, int j)
{
	int	positions[2];
	int	err[3];

	ft_memset(positions, -1, 2 * sizeof(int));
	ft_bzero(err, 3 * sizeof(int));
	while (++positions[0] < j)
	{
		while (++positions[1] < i)
		{
			if (matrix[positions[0]][positions[1]] == 'E')
				err[0]++;
			if (matrix[positions[0]][positions[1]] == 'C')
				err[1]++;
			if (matrix[positions[0]][positions[1]] == 'P')
				err[2]++;
		}
		positions[1] = 0;
	}
	if (err[0] != 1)
		error_msgr("Error parsing exits");
	else if (err[1] == 0)
		error_msgr("Error parsing collectables");
	else if (err[2] != 1)
		error_msgr("Error parsing starting points");
}

void	map_checker(char **matrix, int i, int j)
{
	int	k;

	k = 0;
	while (k < i)
	{
		if (matrix[0][k] != '1' || matrix[j - 1][k] != '1')
			error_msgr("This map has some holes in the walls");
		k++;
	}
	k = 0;
	while (k < j)
	{
		if (matrix[k][0] != '1' || matrix[k][i - 1] != '1')
			error_msgr("This map has some holes in the walls");
		k++;
	}
	parse_check(matrix, i, j - 1);
	map_checker2(matrix, i, j - 1);
}

void	map_arranger(int map, t_win *win)
{
	char	*aux;
	int		i;
	int		j;

	j = 0;
	aux = get_next_line(map);
	i = dimensions_x(aux, 0);
	if (i < 3)
		error_msgr("The map is smaller than a 3x3");
	if (aux[0] != '1')
		error_msgr("The map is not surrounded by walls");
	win->matrix = ft_calloc(1, sizeof(char *) * i);
	win->matrix[j++] = aux;
	while (aux)
	{
		aux = get_next_line(map);
		if (dimensions_x(aux, i) != i)
			error_msgr("This map is not a rectangle");
		win->matrix = (char **) ft_realloc(win->matrix, sizeof(char *) * i * j + 1);
		win->matrix[j++] = aux;
	}
	map_checker(win->matrix, i, j - 1);
	write(1, "MAP LOADED:", 11);
	matrix_printer(win->matrix);
	write(1, "GAME START\n", 11);
}
