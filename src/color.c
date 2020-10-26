/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:33:30 by mcrissy           #+#    #+#             */
/*   Updated: 2020/02/18 17:54:17 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(int x, int y, t_point start, t_point end)
{
	int			red;
	int			green;
	int			blue;
	double		percentage;
	t_point		delta;

	delta.x = end.x - start.x;
	delta.y = end.y - start.y;
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, x);
	else
		percentage = percent(start.y, end.y, y);
	red = get_light((start.color >> 16) & 0xFF,
	(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF,
	(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
