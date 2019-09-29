/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 08:13:14 by jcreux            #+#    #+#             */
/*   Updated: 2019/06/09 15:52:20 by ichemmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_ps	para(t_coords *a, t_coords *b)
{
	t_ps	ps;

	ps.start_x = a->abs + a->alt;
	ps.start_y = a->ord - a->alt;
	ps.end_x = b->abs + b->alt;
	ps.end_y = b->ord - b->alt;
	ps.dx = ps.end_x - ps.start_x;
	ps.dy = ps.end_y - ps.start_y;
	return (ps);
}

t_ps	iso(t_coords *a, t_coords *b)
{
	t_ps	ps;

	ps.start_x = a->abs - a->ord;
	ps.start_y = (a->abs + a->ord) / 2;
	ps.start_y = ps.start_y - a->alt;
	ps.end_x = (b->abs - b->ord);
	ps.end_y = (b->abs + b->ord) / 2;
	ps.end_y = ps.end_y - b->alt;
	ps.dx = ps.end_x - ps.start_x;
	ps.dy = ps.end_y - ps.start_y;
	return (ps);
}
