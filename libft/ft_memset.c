/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:24:44 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/28 22:35:58 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	unsigned char	*res;
	size_t			i;

	i = 0;
	res = (unsigned char *)buf;
	while (count > i)
	{
		res[i] = (unsigned char)ch;
		++i;
	}
	i = 0;
	return (res);
}
