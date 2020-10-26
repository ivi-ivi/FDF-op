/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:54:38 by mcrissy           #+#    #+#             */
/*   Updated: 2020/02/17 18:09:43 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "../libft/libft.h"
# define WIDTH 1500
# define HEIGHT 1000
# define BACKGROUND 0x000000

typedef struct		s_fdf_s_list
{
	int					*i;
	struct s_fdf_s_list	*next;
	int					x_size;
	int					y_size;
}					t_fdf_t_list;

typedef struct		s_point
{
	int				color;
	float			x;
	float			y;
	float			z;
}					t_point;

typedef	struct		s_charact
{
	int				x_ch;
	int				y_ch;
	float			t;
	float			scale;
	float			ratio;
	float			tang;
	float			ang_x;
	float			ang_y;
	float			ang_z;
	float			z_z;
	int				m;
}					t_charact;

typedef struct		s_picture
{
	void			*picture;
	char			*data;
	int				i;
	int				l_size;
	int				j;
}					t_image;

typedef struct		s_mouse
{
	int				x_1;
	int				y_1;
	int				wheel_click;
	int				left_click;
	int				right_click;
}					t_mouse;

typedef struct		s_view
{
	t_mouse			mouse;
	int				**col;
	void			*mlxl;
	void			*win;
	t_image			image;
	t_charact		cam;
	t_point			*dots;
	int				x_s;
	int				y_s;
	int				z_s;
}					t_view;

int					get_color(int x, int y, t_point start, t_point end);
int					do_move(int x, int y, void *param);
void				color1(t_point **t, t_view *w);
void				inc(int *j, int *count);
int					do_click(int button, int x, int y, void *param);
int					do_release(int button, int x, int y, void *param);
t_fdf_t_list		*put_list(int *ar);
void				act(t_view *w);
void				bresenham(t_point st, t_point e, t_view *m);
t_fdf_t_list		*get_map(int fd);
int					get_next_line(const int fd, char **line);
void				projection_main(t_point *t, t_view *w);
void				draw_lines(t_point *t, t_view *w);
t_point				*rotation_main(t_view *w);
double				percent(int start, int end, int current);
int					key_press(int keycode, void *param);
t_fdf_t_list		*new_list(int *ar, int size);
t_view				*create_win(int **ar, int x, int y);
t_point				*get_dots(int **ar, int x, int y, t_view *w);
#endif
