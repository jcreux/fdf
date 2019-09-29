/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 08:21:19 by jcreux            #+#    #+#             */
/*   Updated: 2019/06/10 15:17:50 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include "fdf.h"

int		mlx_leave(void *param)
{
	mlx_destroy_window(((t_mlx *)param)->mlx_ptr, ((t_mlx *)param)->win_ptr);
	exit(ft_free(((t_mlx *)param)->elem));
	return (0);
}

int		error(int i)
{
	write(1, "error\n", 6);
	return (i);
}
