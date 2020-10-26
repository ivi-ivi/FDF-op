/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:01:32 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/28 18:54:25 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_begin(char const *s)
{
	int a;

	a = 0;
	while ((*s == ' ') || (*s == '\n') || (*s == '\t'))
	{
		a++;
		s++;
	}
	return (a);
}

static int	ft_end(char const *s)
{
	int i;

	i = (int)ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	int		i;
	int		a;
	int		b;
	size_t	size;

	if (!s)
		return (NULL);
	i = 0;
	a = ft_begin(s);
	if ((a == (int)ft_strlen(s)) && ((a != 0)))
		return ("");
	b = ft_end(s);
	size = ft_strlen(s) - a - (ft_strlen(s) - b);
	if (!(res = ft_strnew((1 + size))))
		return (NULL);
	while ((s[a + i] && (i + a) <= b))
	{
		res[i] = s[a + i];
		i++;
	}
	return (res);
}
