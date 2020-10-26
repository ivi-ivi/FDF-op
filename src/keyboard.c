/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:32:45 by mcrissy           #+#    #+#             */
/*   Updated: 2020/02/14 18:35:52 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	dop(int keycode, t_view *w)
{
	if (keycode == 126)
		w->cam.y_ch -= 3;
	if (keycode == 125)
		w->cam.y_ch += 3;
	if (keycode == 123)
		w->cam.x_ch -= 3;
	if (keycode == 124)
		w->cam.x_ch += 3;
	if (keycode == 49)
	{
		w->cam.x_ch = WIDTH / 2;
		w->cam.y_ch = HEIGHT / 2;
		w->cam.ang_x = 0;
		w->cam.ang_y = 0;
	}
}

int		key_press(int keycode, void *param)
{
	t_view	*w;

	w = (t_view *)param;
	dop(keycode, w);
	if (keycode == 6)
		w->cam.scale += 0.0001;
	if (keycode == 7)
		w->cam.scale -= 0.0001;
	if (keycode == 12)
		w->cam.z_z += 0.2;
	if (keycode == 13 && w->cam.z_z - 0.2 >= 0.0f)
		w->cam.z_z -= 0.2;
	if (keycode == 18)
		w->cam.m = 0;
	if (keycode == 19)
		w->cam.m = 1;
	if (keycode == 20)
		w->cam.m = 2;
	act(w);
	return (0);
}
