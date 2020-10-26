/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:33:01 by mcrissy           #+#    #+#             */
/*   Updated: 2020/02/14 18:20:54 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		background(t_view *m)
{
	int		*data;
	int		i;
	int		size;

	data = (int	*)m->image.data;
	size = WIDTH * HEIGHT;
	i = -1;
	while (++i < size)
		data[i] = 0x000000;
}

void			act(t_view *m)
{
	t_point	*pnt;

	mlx_clear_window(m->mlxl, m->win);
	background(m);
	pnt = rotation_main(m);
	projection_main(pnt, m);
	draw_lines(pnt, m);
	mlx_put_image_to_window(m->mlxl, m->win, m->image.picture, 0, 0);
}
