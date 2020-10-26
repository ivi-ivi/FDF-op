/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:34:15 by mcrissy           #+#    #+#             */
/*   Updated: 2020/02/14 18:51:00 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf_t_list	*new_list(int *a, int size)
{
	t_fdf_t_list	*list;

	list = (t_fdf_t_list *)malloc(sizeof(t_fdf_t_list));
	list->i = a;
	list->x_size = size;
	list->next = NULL;
	return (list);
}

t_fdf_t_list	*put_list(int *a)
{
	t_fdf_t_list *list;

	list = (t_fdf_t_list *)malloc(sizeof(t_fdf_t_list));
	list->i = a;
	list->next = NULL;
	return (list);
}
