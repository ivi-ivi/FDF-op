/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:00:06 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/27 21:01:43 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	l1;
	size_t	l2;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	while ((int)l1 > i)
	{
		res[i] = s1[i];
		i++;
	}
	while ((int)l2 > ++j)
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (res);
}
