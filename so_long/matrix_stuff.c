/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:21:19 by hmorales          #+#    #+#             */
/*   Updated: 2022/09/28 10:17:07 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*gnl_no_lb(int map)
{
	char	*aux;
	char	*aux2;

	aux = get_next_line(map);
	if (!aux)
		return (NULL);
	aux2 = ft_strtrim(aux, "\n");
	return (aux2);
}

void	parse_check(char **matrix, int i, int j)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < j - 2)
	{
		while (x < i - 2)
		{
			if (matrix[y][x] != '1' && matrix[y][x] != 'C' && \
			matrix[y][x] != 'P' && matrix[y][x] != '0' && matrix[y][x] != 'E')
				error_msgr("There are invalid characters in this map");
			x++;
		}
		x = 0;
		y++;
	}
}

void	matrix_printer(int j, char **matrix)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	write(1, "\n", 1);
	while (y < j)
	{
		while (x < dimensions_x(matrix[y], x))
		{
			write(1, &matrix[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		x = 0;
		y++;
	}
	printf("X: %d, Y: %d\n", dimensions_x(matrix[0], 0), y);
}
