/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:43:11 by jcreux            #+#    #+#             */
/*   Updated: 2019/06/10 14:41:51 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"
#include "libft/libft.h"

static t_coords	*gelem(t_coords *elem, int rank)
{
	int		i;

	i = 0;
	while (i < rank)
	{
		if (elem->next == NULL)
			return (NULL);
		elem = elem->next;
		i++;
	}
	return (elem);
}

static void		print_strings(t_mlx *mlx, char *str)
{
	char	*coords;

	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20, 660, 0xff9900, str);
	coords = ft_itoa(mlx->add_x / 3);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 375, 660, 0xff9900, "x: ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 400, 660, 0xff9900, coords);
	free(coords);
	coords = ft_itoa(mlx->add_y / 3);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 450, 660, 0xff9900, "y: ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 475, 660, 0xff9900, coords);
	free(coords);
	coords = ft_itoa(mlx->add_z - 1);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 525, 660, 0xff9900, "z: ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 550, 660, 0xff9900, coords);
	free(coords);
	coords = ft_itoa(mlx->add_c);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 600, 660, 0xff9900, "zoom: ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 655, 660, 0xff9900, coords);
	free(coords);
}

void			new_img(t_coords *elem, t_mlx *mlx, int proj, char *title)
{
	int			i;
	int			top;
	static char	*str;

	i = 1;
	if (title != NULL)
		str = title;
	top = count_elem(elem);
	mlx->y = (mlx->lines > mlx->ppl) ? mlx->lines : mlx->ppl;
	mlx->y = (mlx->y > top) ? mlx->y : top;
	while (elem && elem->next)
	{
		if (gelem(elem, mlx->ppl) != NULL)
			pseg(mlx, elem, gelem(elem, mlx->ppl), proj);
		if (i % mlx->ppl != 0)
			pseg(mlx, elem, elem->next, proj);
		elem = elem->next;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	print_strings(mlx, str);
}
