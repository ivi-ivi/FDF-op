/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:34:59 by mcrissy           #+#    #+#             */
/*   Updated: 2020/02/17 18:05:59 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_lines(t_point *t, t_view *w)
{
	int	i;
	int	size;

	size = w->x_s * w->y_s;
	i = -1;
	while (++i < size)
	{
		if (i % w->x_s == w->x_s - 1)
			;
		else
			bresenham(t[i], t[i + 1], w);
	}
	i = -1;
	while (++i < size)
	{
		if (i + w->x_s == size)
			break ;
		bresenham(t[i], t[i + w->x_s], w);
	}
	free(t);
}
