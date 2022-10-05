/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:28:38 by hmorales          #+#    #+#             */
/*   Updated: 2022/10/05 11:51:19 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	char	*str;
	int		fd;

	//atexit(leaks);
	fd = 0;
	if (argc > 2)
		error_msgr("Too many arguments");
	else if (argc < 2)
		error_msgr("Please submit a map");
	str = ft_strnstr(ft_strrchr(argv[1], '.'), ".ber", 4);
	if (str && ft_strlen(str) == 4)
	{
		fd = open(argv[1], O_RDONLY);
		map_render(fd);
		close(fd);
		return (0);
	}
	else
		write(1, "Only .ber files are accepted", 28);
	return (0);
}
