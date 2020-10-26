/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:34:52 by mcrissy           #+#    #+#             */
/*   Updated: 2020/02/18 17:48:21 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	projection(t_point *t, t_view *w)
{
	t->z += 10;
	t->x = (float)w->cam.ratio * w->cam.tang * t->x;
	t->y = (float)w->cam.tang * t->y;
	t->y *= w->cam.scale * HEIGHT;
	t->x *= w->cam.scale * WIDTH;
	t->x += w->cam.x_ch;
	t->y += w->cam.y_ch;
}

void		projection_main(t_point *t, t_view *w)
{
	int i;
	int j;

	j = w->x_s * w->y_s;
	i = -1;
	while (++i < j)
		projection(&t[i], w);
}
