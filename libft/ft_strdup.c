/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:32:39 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/28 23:12:38 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char			*res;
	int				i;
	int				j;

	j = 0;
	i = ft_strlen(str);
	if (!(res = ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i > j)
	{
		res[j] = str[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}
