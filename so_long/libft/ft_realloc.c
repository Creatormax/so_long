/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:41:17 by hmorales          #+#    #+#             */
/*   Updated: 2022/01/24 19:32:44 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t ex, size_t size)
{
	void	*tmp;

	if (!ptr)
		return ((void *)malloc(size));
	tmp = (void *)malloc(size);
	if (!tmp)
		return (NULL);
	ft_memmove(tmp, ptr, ex);
	free(ptr);
	ptr = ((void *)malloc(size));
	if (!ptr)
		return (NULL);
	ft_memmove(ptr, tmp, size);
	free(tmp);
	return (ptr);
}
