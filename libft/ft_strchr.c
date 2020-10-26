/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:58:45 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/28 23:26:18 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char *s;

	s = (char *)str;
	while (*s)
	{
		if (*s == ch)
			return (s);
		s++;
	}
	if (ch == '\0')
		return (s);
	return (NULL);
}
