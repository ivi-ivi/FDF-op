/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:16:35 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/28 22:48:40 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int ch, size_t count)
{
	char	*res;
	char	c;
	char	*s;

	res = (char *)dest;
	s = (char *)source;
	c = (char)ch;
	while (count > 0 && *s != c)
	{
		count--;
		*res++ = *s++;
	}
	if (count > 0)
	{
		*res++ = *s++;
		return ((void *)res);
	}
	else
		return (NULL);
}
