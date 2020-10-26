/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:34:43 by mcrissy           #+#    #+#             */
/*   Updated: 2020/02/18 17:54:26 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

static void	clear(int **a, int y)
{
	int i;

	i = -1;
	while (++i < y)
		free(a[i]);
	free(a);
}

void		color(t_point *t, t_view *w)
{
	double per;

	if (w->cam.m == 4)
		t->color = 0x00000000;
	per = percent(0, w->z_s, t->z < 0 ? -t->z : t->z);
	if (per < 0.2)
		t->color = w->col[w->cam.m][0];
	else if (per < 0.4)
		t->color = w->col[w->cam.m][1];
	else if (per < 0.6)
		t->color = w->col[w->cam.m][2];
	else if (per < 0.8)
		t->color = w->col[w->cam.m][3];
	else
		t->color = w->col[w->cam.m][4];
}

void		color1(t_point **t, t_view *w)
{
	int i;

	i = -1;
	while (++i < w->x_s * w->y_s)
		color(&(*t)[i], w);
}

void		new(int *i, int *k, int *maxofz)
{
	*maxofz = 0;
	*i = 0;
	*k = 0;
}

t_point		*get_dots(int **a, int x, int y, t_view *w)
{
	t_point	*dots;
	int		maxofz;
	int		i;
	int		j;
	int		k;

	dots = (t_point *)malloc(sizeof(t_point) * x * y);
	new(&i, &k, &maxofz);
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (maxofz < abs(a[i][j]))
				maxofz = abs(a[i][j]);
			dots[k].x = j - x / 2;
			dots[k].y = i - y / 2;
			dots[k].z = -a[i][j];
			inc(&j, &k);
		}
		++i;
	}
	w->z_s = maxofz;
	clear(a, y);
	return (dots);
}
