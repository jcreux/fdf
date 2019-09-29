/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 07:10:45 by jcreux            #+#    #+#             */
/*   Updated: 2019/06/09 21:19:32 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft/libft.h"

static char	*fill_pixel(t_mlx *list, int x, int y, char *color)
{
	if (y >= 0 && y < WIN_SIZE && x >= 0 && x < WIN_SIZE)
	{
		list->img_data[x * 4 + WIN_SIZE * y * 4] = hex_to_dec(color + 6);
		list->img_data[(x * 4 + WIN_SIZE * y * 4) + 1] = hex_to_dec(color + 4);
		list->img_data[(x * 4 + WIN_SIZE * y * 4) + 2] = hex_to_dec(color + 2);
		list->img_data[(x * 4 + WIN_SIZE * y * 4) + 3] = hex_to_dec(color);
	}
	free(color);
	return (list->img_data);
}

static char	*seg_color(char *color_a, char *color_b, t_ps *ps, int token)
{
	double	p;
	double	pp;
	int		red;
	int		green;
	int		blue;

	if (token == 0)
		p = (double)(ps->x - ps->start_x) / (double)(ps->end_x - ps->start_x);
	else
		p = (double)(ps->y - ps->start_y) / (double)(ps->end_y - ps->start_y);
	pp = 1 - p;
	red = (hex_to_dec(color_a + 2) * pp) + (hex_to_dec(color_b + 2) * p);
	green = (hex_to_dec(color_a + 4) * pp) + (hex_to_dec(color_b + 4) * p);
	blue = (hex_to_dec(color_a + 6) * pp) + (hex_to_dec(color_b + 6) * p);
	return (dec_to_hex(red, green, blue));
}

static void	pseg_h(t_mlx *mlx, t_ps *ps, t_coords *a, t_coords *b)
{
	ps->cumul = ps->dx / 2;
	while (ps->i <= ps->dx)
	{
		ps->x = ps->x + ps->xinc;
		ps->cumul = ps->cumul + ps->dy;
		if (ps->cumul >= ps->dx)
		{
			ps->cumul = ps->cumul - ps->dx;
			ps->y = ps->y + ps->yinc;
		}
		fill_pixel(mlx, ps->x, ps->y, seg_color(a->color, b->color, ps, 0));
		ps->i++;
	}
}

static void	pseg_v(t_mlx *mlx, t_ps *ps, t_coords *a, t_coords *b)
{
	ps->cumul = ps->dy / 2;
	while (ps->i <= ps->dy)
	{
		ps->y = ps->y + ps->yinc;
		ps->cumul = ps->cumul + ps->dx;
		if (ps->cumul >= ps->dy)
		{
			ps->cumul = ps->cumul - ps->dy;
			ps->x = ps->x + ps->xinc;
		}
		fill_pixel(mlx, ps->x, ps->y, seg_color(a->color, b->color, ps, 1));
		ps->i++;
	}
}

char		*pseg(t_mlx *mlx, t_coords *a, t_coords *b, int proj)
{
	t_ps	ps;

	ps = init_proj(mlx, *a, *b, proj);
	ps.i = 1;
	if (ps.dx > 0)
		ps.xinc = 1;
	else
		ps.xinc = -1;
	if (ps.dy > 0)
		ps.yinc = 1;
	else
		ps.yinc = -1;
	ps.dx = ft_abs(ps.dx);
	ps.dy = ft_abs(ps.dy);
	fill_pixel(mlx, ps.x, ps.y, ft_strdup(a->color));
	if (ps.dx > ps.dy)
		pseg_h(mlx, &ps, a, b);
	else
		pseg_v(mlx, &ps, a, b);
	return (mlx->img_data);
}
