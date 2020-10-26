/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:40:41 by mcrissy           #+#    #+#             */
/*   Updated: 2019/09/28 23:37:23 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	if (*str2 == '\0' && *str1 == '\0')
		return (0);
	while ((*str1 == *str2) && (*str1 != '\0') && (*str2 != '\0'))
	{
		str2++;
		str1++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
