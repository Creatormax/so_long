/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:09:04 by hmorales          #+#    #+#             */
/*   Updated: 2021/11/26 17:29:00 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap_bonus(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*last;

	last = 0;
	while (lst)
	{
		first = ft_lstnew_bonus(f(lst->content));
		if (!first)
		{
			ft_lstclear_bonus(&last, del);
			return (0);
		}
		ft_lstadd_back_bonus(&last, first);
		lst = lst->next;
	}
	return (last);
}
