/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:59:28 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/26 16:52:37 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	i = start;
	if (!(res = ft_strnew(len)))
		return (NULL);
	if (!s)
		return (NULL);
	res = ft_strncpy(res, &(s[i]), len);
	return (res);
}
