/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:34:35 by mcrissy           #+#    #+#             */
/*   Updated: 2020/02/18 17:53:50 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	place_coords(t_view *w, int x, int y)
{
	w->mouse.x_1 = x;
	w->mouse.y_1 = y;
}

int		do_click(int command, int x, int y, void *p)
{
	t_view *w;

	w = (t_view *)p;
	if (command == 1)
	{
		place_coords(w, x, y);
		w->mouse.left_click = 1;
	}
	if (command == 2)
	{
		place_coords(w, x, y);
		w->mouse.right_click = 1;
	}
	if (command == 3)
	{
		place_coords(w, x, y);
		w->mouse.wheel_click = 1;
	}
	if (command == 4)
		w->cam.scale -= 0.0005;
	if (command == 5)
		w->cam.scale += 0.0005;
	act(w);
	return (0);
}

int		do_release(int command, int x, int y, void *p)
{
	t_view *w;

	(void)x;
	(void)y;
	w = (t_view *)p;
	if (command == 1)
		w->mouse.left_click = 0;
	if (command == 2)
		w->mouse.right_click = 0;
	if (command == 3)
		w->mouse.wheel_click = 0;
	return (0);
}

int		do_move(int x, int y, void *p)
{
	t_view *w;

	w = (t_view *)p;
	if (w->mouse.left_click)
	{
		w->cam.x_ch += (x - w->mouse.x_1);
		w->cam.y_ch += (y - w->mouse.y_1);
		place_coords(w, x, y);
	}
	if (w->mouse.wheel_click)
	{
		if (w->cam.z_z + (-y + w->mouse.y_1) * 0.001 >= 0.0f)
			w->cam.z_z += (-y + w->mouse.y_1) * 0.001;
		place_coords(w, x, y);
	}
	if (w->mouse.right_click)
	{
		w->cam.ang_x += (-y + w->mouse.y_1) * 0.1;
		w->cam.ang_y += (x - w->mouse.x_1) * 0.1;
		place_coords(w, x, y);
	}
	act(w);
	return (0);
}
