/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:27:07 by hmorales          #+#    #+#             */
/*   Updated: 2022/03/03 18:18:09 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dimensions_x(char *aux, int j)
{
	int		i;

	i = 0;
	if (!aux)
		return (j);
	while (aux[i])
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

	positions[0] = -1;
	positions[1] = -1;
	ft_bzero(err, 3);
	while (++positions[0] < j - 1)
	{
		while (++positions[1] < i - 1)
		{
			if (matrix[positions[0]][positions[1]] == 'E')
				err[0] = 1;
			if (matrix[positions[0]][positions[1]] == 'C')
				err[1] = 1;
			if (matrix[positions[0]][positions[1]] == 'P')
				err[2] = 1;
		}
		positions[1] = 0;
	}
	if (err[0] == 0)
		error_msgr("There is no exit");
	else if (err[1] == 0)
		error_msgr("There are no collectables");
	else if (err[2] == 0)
		error_msgr("There is no starting point");
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
	matrix_printer(j, matrix);
	map_checker2(matrix, i, j - 1);
}

char	**map_arranger(int map)
{
	char	**matrix;
	char	*aux;
	int		i;
	int		j;

	j = 0;
	aux = gnl_no_lb(map);
	i = dimensions_x(aux, 0);
	if (i < 3)
		error_msgr("The map is smaller than a 3x3");
	if (aux[0] != '1')
		error_msgr("The map is not surrounded by walls");
	matrix = ft_calloc(1, sizeof(char *) * i);
	matrix[j++] = aux;
	while (aux)
	{
		aux = gnl_no_lb(map);
		if (dimensions_x(aux, i) != i)
			error_msgr("This map is not a rectangle");
		matrix = (char **) ft_realloc(matrix, sizeof(char *) * i * j + 1, \
		sizeof(char *) * i * j);
		matrix[j++] = aux;
	}
	map_checker(matrix, i, j - 1);
	return (matrix);
}
