/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:27:14 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/28 18:07:29 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *memptr1, const void *memptr2, size_t num)
{
	unsigned char *m1;
	unsigned char *m2;

	m1 = (unsigned char *)memptr1;
	m2 = (unsigned char *)memptr2;
	while (num > 0)
	{
		if (*m1 != *m2)
			return (*m1 - *m2);
		num--;
		m1++;
		m2++;
	}
	return (0);
}
