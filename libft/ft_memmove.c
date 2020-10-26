/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:21:52 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/28 23:10:26 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	char	*res;
	char	*s;
	size_t	i;

	i = 0;
	res = (char *)dest;
	s = (char *)src;
	if (dest == NULL && src == NULL && num)
		return (NULL);
	if (s < res)
	{
		i = num;
		while (i-- > 0)
			res[i] = s[i];
	}
	else
		while (num > i)
		{
			res[i] = s[i];
			i++;
		}
	return (res);
}
