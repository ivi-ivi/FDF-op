/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:33:43 by mcrissy           #+#    #+#             */
/*   Updated: 2020/02/19 16:15:58 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

static void	put_pixel(int x, int y, int color, t_view *m)
{
	int	i;

	if (!(y < 0 || x >= WIDTH || y >= HEIGHT))
	{
		i = (x * m->image.i / 8) + (y * m->image.l_size);
		m->image.data[i] = color;
		m->image.data[++i] = color >> 8;
		m->image.data[++i] = color >> 16;
		m->image.data[++i] = 0;
	}
}

void		bresenham(t_point st, t_point e, t_view *m)
{
	int s[2];
	int step[2];
	int x;
	int y;

	s[0] = (int)st.x < (int)e.x ? 1 : -1;
	s[1] = (int)st.y < (int)e.y ? 1 : -1;
	x = (int)st.x;
	y = (int)st.y;
	step[0] = abs((int)e.x - (int)st.x) - abs((int)e.y - (int)st.y);
	while ((x - s[0]) != (int)e.x && (y - s[1]) != (int)e.y)
	{
		put_pixel(x, y, get_color(x, y, st, e), m);
		step[1] = 2 * step[0];
		step[0] += (step[1] >= -abs((int)e.y - (int)st.y)) ?
		-abs((int)e.y - (int)st.y) : 0;
		x += (step[1] >= -abs((int)e.y - (int)st.y)) ? s[0] : 0;
		step[0] += (step[1] <= abs((int)e.x - (int)st.x)) ?
		abs((int)e.x - (int)st.x) : 0;
		y += (step[1] <= abs((int)e.x - (int)st.x)) ? s[1] : 0;
	}
}
