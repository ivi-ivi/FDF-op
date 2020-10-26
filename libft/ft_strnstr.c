/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:39:32 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/28 17:58:50 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	k;
	char	*res;
	char	*s2;

	i = 0;
	res = (char *)str1;
	s2 = (char *)str2;
	if (s2[i] == '\0')
		return (res);
	while (res[i] && (i < len))
	{
		k = 0;
		while ((res[i + k] != '\0')
				&& (str2[k] == res[i + k]) && ((i + k) < len))
		{
			if (str2[1 + k] == '\0')
				return (&res[i]);
			k++;
		}
		i++;
	}
	return (NULL);
}
