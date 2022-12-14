/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:14:56 by hmorales          #+#    #+#             */
/*   Updated: 2022/12/14 12:11:56 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dimensions_y(char **matrix)
{
	int	j;

	j = 0;
	while (matrix[j])
		j++;
	return (j);
}

void	console_esthetics(t_win win)
{
	write(1, "MAP LOADED:", 11);
	matrix_printer(win.matrix);
	write(1, "GAME START\n", 11);
}

char **matrix_zero(int i, int j, t_win win, char** aux)
{
	if (win.matrix[i][j] == '1')
		aux[i][j] = '1';
	else
		aux[i][j] = '0';
	return (aux);
}
