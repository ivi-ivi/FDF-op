/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:41:42 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/28 19:15:08 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	if (*s2 == '\0' && *s1 == '\0')
		return (0);
	while ((*s1 == *s2) && ((--n) > 0) && (*s1) && (*s2))
	{
		s2++;
		s1++;
	}
	return ((int)(*s1 - *s2));
}
