/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:32:33 by mcrissy           #+#    #+#             */
/*   Updated: 2020/02/14 18:42:06 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_point	rotation(t_point *l, t_view *fdf)
{
	t_point	elem;
	float	a;
	float	b;
	float	t;

	elem.color = l->color;
	a = cosf(fdf->cam.ang_x / 180.0f * 3.14159f);
	b = sinf(fdf->cam.ang_x / 180.0f * 3.14159f);
	elem.y = (float)a * l->y + b * l->z * fdf->cam.z_z;
	elem.z = (float)a * l->z * fdf->cam.z_z - b * l->y;
	elem.x = l->x;
	a = cosf(fdf->cam.ang_y / 180.0f * 3.14159f);
	b = sinf(fdf->cam.ang_y / 180.0f * 3.14159f);
	t = elem.x;
	elem.x = (float)a * elem.x - b * elem.z;
	elem.z = (float)a * elem.z + b * t;
	a = cosf(fdf->cam.ang_z / 180.0f * 3.14159f);
	b = sinf(fdf->cam.ang_z / 180.0f * 3.14159f);
	t = elem.x;
	elem.x = (float)a * elem.x + b * elem.y;
	elem.y = (float)a * elem.y - b * t;
	return (elem);
}

t_point			*rotation_main(t_view *fdf)
{
	t_point	*elem;
	int		i;
	int		s;

	color1(&fdf->dots, fdf);
	s = fdf->x_s * fdf->y_s;
	elem = (t_point *)malloc(s * sizeof(t_point));
	i = -1;
	while (++i < s)
		elem[i] = rotation(&fdf->dots[i], fdf);
	return (elem);
}
