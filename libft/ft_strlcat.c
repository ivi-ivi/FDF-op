/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:48:56 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/28 17:43:48 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		i;
	size_t		l;

	d = dest;
	s = src;
	i = size;
	while (i-- != 0 && *d != '\0')
		++d;
	l = d - dest;
	i = size - l;
	if (i == 0)
		return (l + ft_strlen(s));
	while (*s != '\0')
	{
		if (i != 1)
		{
			*d++ = *s;
			--i;
		}
		++s;
	}
	*d = '\0';
	return (l + (s - src));
}
