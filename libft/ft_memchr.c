/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:25:01 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/28 23:06:32 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*res;
	size_t			i;

	res = (unsigned char *)arr;
	i = 0;
	while (n > i)
	{
		if (res[i] == (unsigned char)c)
			return (&res[i]);
		i++;
	}
	return (NULL);
}
