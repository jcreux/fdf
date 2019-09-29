/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_proj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:34:59 by jcreux            #+#    #+#             */
/*   Updated: 2019/06/09 19:35:48 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coords	init_point(t_mlx *mlx, int c, t_coords point)
{
	point.abs -= mlx->ppl / 2;
	point.ord -= mlx->lines / 2;
	point.abs *= c;
	point.ord *= c;
	point.alt = point.alt * c * mlx->add_z;
	return (point);
}

t_ps			init_proj(t_mlx *mlx, t_coords a, t_coords b, int proj)
{
	t_ps	ps;

	ps.c = (WIN_SIZE / mlx->y / 2 >= 1) ? WIN_SIZE / mlx->y / 2 : 1;
	ps.c += mlx->add_c;
	if (ps.c <= 0)
	{
		mlx->add_c += 1;
		ps.c = 1;
	}
	a = init_point(mlx, ps.c, a);
	b = init_point(mlx, ps.c, b);
	if (proj == 0)
		ps = iso(&a, &b);
	else if (proj == 1)
		ps = para(&a, &b);
	ps.start_x += mlx->add_x + WIN_SIZE / 2;
	ps.start_y += mlx->add_y + WIN_SIZE / 2;
	ps.end_x += mlx->add_x + WIN_SIZE / 2;
	ps.end_y += mlx->add_y + WIN_SIZE / 2;
	ps.x = ps.start_x;
	ps.y = ps.start_y;
	return (ps);
}
