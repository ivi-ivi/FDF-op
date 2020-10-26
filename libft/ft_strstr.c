/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:07:01 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/28 23:33:38 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	k;

	res = (char *)str1;
	if (ft_strlen(str2) == 0)
		return (res);
	i = 0;
	j = 0;
	k = 0;
	while (res[i])
	{
		while ((str2[j]) && (str2[j] == res[k]))
		{
			j++;
			k++;
		}
		if (j == ft_strlen(str2))
			return (&res[i]);
		i++;
		k = i;
		j = 0;
	}
	return (NULL);
}
