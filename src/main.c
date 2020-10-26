/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:34:26 by mcrissy           #+#    #+#             */
/*   Updated: 2020/02/18 17:53:58 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/fdf.h"

static int	list_len(t_fdf_t_list *l)
{
	t_fdf_t_list	*list;
	int				i;

	list = l;
	i = 0;
	while (list)
	{
		++i;
		list = list->next;
	}
	return (i);
}

static int	**map_size(t_fdf_t_list *l, int *x, int *y)
{
	t_fdf_t_list	*list;
	int				**map;
	int				i;

	i = 0;
	map = (int **)malloc(list_len(l) * sizeof(t_fdf_t_list));
	*x = l->x_size;
	while (l)
	{
		map[i] = l->i;
		++i;
		list = l->next;
		free(l);
		l = list;
	}
	*y = i;
	return (map);
}

int			main(int ac, char **av)
{
	int				**map;
	int				fd;
	t_view			*fdf;
	int				d[2];
	t_fdf_t_list	*t;

	if (ac != 2)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	if (!(t = get_map(fd)))
		return (0);
	map = map_size(t, &d[0], &d[1]);
	fdf = create_win(map, d[0], d[1]);
	act(fdf);
	mlx_hook(fdf->win, 2, 0, key_press, fdf);
	mlx_hook(fdf->win, 4, 0, do_click, fdf);
	mlx_hook(fdf->win, 5, 0, do_release, fdf);
	mlx_hook(fdf->win, 6, 0, do_move, fdf);
	mlx_loop(fdf->mlxl);
}
