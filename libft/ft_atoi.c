/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:48:48 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/28 19:56:38 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int						i;
	unsigned int long long	res;
	int						fl;

	res = 0;
	i = 0;
	fl = 1;
	while (*(str + i) == '\n' || *(str + i) == '\t' || *(str + i) == '\r'
			|| *(str + i) == '\v' || *(str + i) == '\f' || *(str + i) == ' ')
		i++;
	if (*(str + i) == '-')
		fl = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
	{
		if ((res > 9223372036854775807) && (fl == 1))
			return (-1);
		if ((res > 9223372036854775807) && (fl == -1))
			return (0);
		res = res * 10 + (*(str + i) - '0');
		i++;
	}
	return (res * fl);
}
