/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:00:52 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/28 23:31:58 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*s;
	int		l;

	s = (char *)str;
	l = ft_strlen(s);
	while (l && s[l] != (char)ch)
		--l;
	if (s[l] == ch)
		return (&s[l]);
	return (NULL);
}
