/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09:35:44 by jcreux            #+#    #+#             */
/*   Updated: 2019/06/09 09:36:46 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fdf.h"

static int	min_val(t_coords *list)
{
	int i;

	i = 0;
	if (!(list))
		return (0);
	while (list->next != NULL)
	{
		if (list->alt < i)
			i = list->alt;
		list = list->next;
	}
	return (i);
}

static int	max_val(t_coords *list)
{
	int i;

	i = 0;
	if (!(list))
		return (0);
	while (list->next != NULL)
	{
		if (list->alt > i)
			i = list->alt;
		list = list->next;
	}
	return (i);
}

int			count_elem(t_coords *list)
{
	int		ret;
	int		start;
	int		end;

	start = min_val(list);
	end = max_val(list);
	ret = 0;
	while (start != end)
	{
		start++;
		ret++;
	}
	return (ret);
}
