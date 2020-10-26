/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:05:20 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/28 23:03:04 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	char	*res;
	char	*s;
	size_t	i;

	if (!dest && !src && count)
		return (NULL);
	i = -1;
	s = (char *)src;
	res = dest;
	while (++i < count)
		*(res + i) = *(s + i);
	return (dest);
}
