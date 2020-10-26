/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:33:54 by mcrissy           #+#    #+#             */
/*   Updated: 2020/02/17 18:07:30 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"

void			clear(char **str)
{
	int i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

static int		buff_len(char **buff)
{
	int i;

	i = 0;
	while (buff[i])
		i++;
	return (i);
}

static int		*str_parse(char **buff)
{
	int	*array;
	int	i;

	array = (int*)malloc(buff_len(buff) * sizeof(int));
	i = 0;
	while (buff[i])
	{
		array[i] = ft_atoi(buff[i]);
		i++;
	}
	return (array);
}

t_fdf_t_list	*get_map(int fd)
{
	t_fdf_t_list	*res;
	t_fdf_t_list	*tmp;
	char			*buff;
	char			**split;

	get_next_line(fd, &buff);
	if (!*buff)
		exit(0);
	split = ft_strsplit(buff, ' ');
	tmp = new_list(str_parse(split), buff_len(split));
	res = tmp;
	free(buff);
	clear(split);
	while (get_next_line(fd, &buff))
	{
		split = ft_strsplit(buff, ' ');
		res->next = put_list(str_parse(split));
		if (tmp->x_size != buff_len(split))
			return (NULL);
		res = res->next;
		clear(split);
		free(buff);
	}
	return (tmp);
}
