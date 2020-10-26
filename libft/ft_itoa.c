/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:47:55 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/27 15:31:55 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoa_len(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		++i;
	while (n /= 10)
		++i;
	++i;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*res;
	size_t			l;
	unsigned int	b;

	l = ft_itoa_len(n);
	b = n;
	if (n < 0)
		b *= (-1);
	if (!(res = ft_strnew(l)))
		return (NULL);
	res[--l] = b % 10 + '0';
	while (b /= 10)
	{
		--l;
		res[l] = b % 10 + '0';
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
