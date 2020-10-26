/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:24:17 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/27 19:40:37 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *res;

	newlist = f(lst);
	res = newlist;
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (!(newlist->next = f(lst)))
		{
			free(newlist->next);
			return (NULL);
		}
		newlist = newlist->next;
	}
	return (res);
}
