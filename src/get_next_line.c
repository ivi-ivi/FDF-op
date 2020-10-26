/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:47:13 by mcrissy           #+#    #+#             */
/*   Updated: 2019/10/21 17:47:31 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*rest_chars(char *rest_of_buff, char **ptr)
{
	char *line;

	if ((*ptr = ft_strchr(rest_of_buff, '\n')))
	{
		line = ft_strsub(rest_of_buff, 0, *ptr - rest_of_buff);
		ft_strcpy(rest_of_buff, ++(*ptr));
	}
	else
	{
		line = ft_strnew(ft_strlen(rest_of_buff) + 1);
		ft_strcat(line, rest_of_buff);
		ft_strclr(rest_of_buff);
	}
	return (line);
}

int				ft_string(const int fd, char **line, char *rest)
{
	char	buff[BUFF_SIZE + 1];
	int		count;
	char	*ptr;
	char	*tmp;

	ptr = NULL;
	*line = rest_chars(rest, &ptr);
	count = 1;
	while (!ptr && ((count = read(fd, buff, BUFF_SIZE)) != 0))
	{
		buff[count] = '\0';
		if ((ptr = ft_strchr(buff, '\n')))
		{
			ft_strcpy(rest, ++ptr);
			ft_strclr(--ptr);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buff)) || count < 0)
			return (-1);
		free(tmp);
	}
	if (ft_strlen(rest) || ft_strlen(*line) || count)
		return (1);
	else
		return (0);
}

t_list_gnl		*new_fd(const int fd)
{
	t_list_gnl	*elem;

	if (!(elem = (t_list_gnl *)malloc(sizeof(t_list_gnl))))
		return (NULL);
	elem->fd = fd;
	elem->rest_of_buff = ft_strnew(BUFF_SIZE);
	elem->next = NULL;
	return (elem);
}

int				get_next_line(const int fd, char **line)
{
	static t_list_gnl	*first;
	t_list_gnl			*list;

	if (fd < 0 || line == 0)
		return (-1);
	if (!first)
		first = new_fd(fd);
	list = first;
	while (list->fd != fd)
	{
		if (list->next == NULL)
			list->next = new_fd(fd);
		list = list->next;
	}
	return (ft_string(fd, line, list->rest_of_buff));
}
