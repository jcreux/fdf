/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 10:31:18 by jcreux            #+#    #+#             */
/*   Updated: 2019/06/10 19:17:56 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

int		ft_free(t_coords *elem)
{
	t_coords	*last;

	if (elem == NULL)
		return (1);
	while (elem)
	{
		last = elem->next;
		free(elem->color);
		free(elem);
		elem = last;
	}
	return (1);
}
