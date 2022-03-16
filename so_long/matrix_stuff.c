/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:21:19 by hmorales          #+#    #+#             */
/*   Updated: 2022/01/21 17:17:02 by hmorales         ###   ########.fr       */
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

void	matrix_printer(int j, char **matrix)
{
	int	y;

	y = 0;
	printf("%d\n", dimensions_y(matrix));
	while (y <= j)
	{
		printf("%d ", dimensions_x(matrix[y], 0));
		printf("%s\n", matrix[y++]);
	}
}
