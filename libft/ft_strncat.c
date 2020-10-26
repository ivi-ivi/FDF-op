/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:46:35 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/28 23:24:11 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int				i;
	int				j;

	i = 0;
	j = ft_strlen(dest);
	while ((src[i]) && (n > 0))
	{
		dest[j] = src[i];
		i++;
		j++;
		--n;
	}
	dest[j] = '\0';
	return (dest);
}
