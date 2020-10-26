/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:47:30 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/27 18:57:52 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	while ((*s != c) && (*s != '\0'))
	{
		++i;
		++s;
	}
	return (i);
}

static int		ft_wordnum(char const *s, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if ((*s != c) && (*s != '\0'))
			++i;
		while ((*s != c) && (*s != '\0'))
			s++;
	}
	return (i);
}

static char		**ft_res(char const *s, char c, char **res)
{
	int	i;
	int	k;
	int	n;

	i = 0;
	n = 0;
	while (i < ft_wordnum(s, c))
	{
		k = 0;
		if (!(res[i] = ft_strnew(ft_wordlen(&s[n], c) + 1)))
			res[i] = NULL;
		while (s[n] == c)
			n++;
		while (s[n] != c && s[n])
		{
			res[i][k] = s[n];
			k++;
			n++;
		}
		res[i][k] = '\0';
		i++;
	}
	res[i] = 0;
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char **res;

	if (!s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(*res) * (ft_wordnum(s, c) + 1))))
		return (NULL);
	ft_res(s, c, res);
	return (res);
}
