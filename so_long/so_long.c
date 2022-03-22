/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:28:38 by hmorales          #+#    #+#             */
/*   Updated: 2022/03/22 16:16:16 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*str;

	if (argc > 2)
	{
		write(1, "Too many arguments", 19);
		return (0);
	}
	else if (argc < 2)
	{
		write(1, "Please submit a map", 20);
		return (0);
	}
	str = ft_strnstr(ft_strrchr(argv[1], '.'), ".ber", 4);
	if (str && ft_strlen(str) == 4)
	{
		map_render(open(argv[1], O_RDONLY));
		return (0);
	}
	else
		write(1, "Only .ber files are accepted", 29);
	return (0);
}
