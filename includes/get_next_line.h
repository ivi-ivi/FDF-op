/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:16:56 by mcrissy           #+#    #+#             */
/*   Updated: 2020/02/13 17:08:06 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000000
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"

int				get_next_line(const int fd, char **line);

typedef struct	s_list_gnl
{
	int					fd;
	char				*rest_of_buff;
	struct s_list_gnl	*next;
}				t_list_gnl;

#endif
