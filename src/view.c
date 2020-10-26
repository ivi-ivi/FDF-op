/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:33:18 by mcrissy           #+#    #+#             */
/*   Updated: 2020/02/17 18:00:29 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

void				inc(int *j, int *count)
{
	(*j)++;
	(*count)++;
}

static void			init_color(int **col)
{
	col[0][0] = COLOR_1_1;
	col[0][1] = COLOR_1_2;
	col[0][2] = COLOR_1_3;
	col[0][3] = COLOR_1_4;
	col[0][4] = COLOR_1_5;
	col[1][0] = COLOR_2_1;
	col[1][1] = COLOR_2_2;
	col[1][2] = COLOR_2_3;
	col[1][3] = COLOR_2_4;
	col[1][4] = COLOR_2_5;
	col[2][0] = COLOR_3_1;
	col[2][1] = COLOR_3_2;
	col[2][2] = COLOR_3_3;
	col[2][3] = COLOR_3_4;
	col[2][4] = COLOR_3_5;
}

static t_charact	create_cam(void)
{
	t_charact cam;

	cam.ratio = (float)HEIGHT / WIDTH;
	cam.x_ch = WIDTH / 2;
	cam.y_ch = HEIGHT / 2;
	cam.t = 90;
	cam.ang_x = 0;
	cam.ang_y = 0;
	cam.ang_z = 0;
	cam.tang = (float)1.0f / tanf(cam.t / 2 / 180 * 3.14159);
	cam.scale = 0.001;
	cam.z_z = 1;
	cam.m = 0;
	return (cam);
}

t_mouse				create_mouse(void)
{
	t_mouse m;

	m.left_click = 0;
	m.right_click = 0;
	m.wheel_click = 0;
	return (m);
}

t_view				*create_win(int **ar, int x, int y)
{
	t_view *m;

	if (!(m = (t_view*)malloc(sizeof(t_view))))
		return (NULL);
	if (!(m->mlxl = mlx_init()))
		return (NULL);
	if (!(m->win = mlx_new_window(m->mlxl, WIDTH, HEIGHT, "Win")))
		return (NULL);
	if (!(m->image.picture = mlx_new_image(m->mlxl, WIDTH, HEIGHT)))
		return (NULL);
	m->image.data = mlx_get_data_addr(m->image.picture, &m->image.i,
			&m->image.l_size, &m->image.j);
	m->cam = create_cam();
	m->col = malloc(sizeof(int*) * 5);
	m->col[0] = malloc(sizeof(int) * 5);
	m->col[1] = malloc(sizeof(int) * 5);
	m->col[2] = malloc(sizeof(int) * 5);
	init_color(m->col);
	m->dots = get_dots(ar, x, y, m);
	m->x_s = x;
	m->y_s = y;
	m->mouse = create_mouse();
	return (m);
}
