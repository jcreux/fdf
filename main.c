/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 00:05:27 by jcreux            #+#    #+#             */
/*   Updated: 2019/06/10 19:24:16 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"
#include "libft/libft.h"

static void		get_key(int key, t_mlx *mlx)
{
	if (key == 1)
		mlx->add_z -= 0.002 * mlx->ppl;
	else if (key == 13)
		mlx->add_z += 0.002 * mlx->ppl;
	else if (key == 18)
		mlx->proj = 0;
	else if (key == 19)
		mlx->proj = 1;
	else if (key == 24)
		mlx->add_c += 1;
	else if (key == 27)
		mlx->add_c -= 1;
	else if (key == 123)
		mlx->add_x -= 3;
	else if (key == 124)
		mlx->add_x += 3;
	else if (key == 125)
		mlx->add_y += 3;
	else if (key == 126)
		mlx->add_y -= 3;
}

static int		mlx_key_press(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(ft_free(mlx->elem));
	}
	else
	{
		ft_memset(mlx->img_data, 0, mlx->sl * WIN_SIZE);
		get_key(key, mlx);
		new_img(mlx->elem, mlx, mlx->proj, NULL);
	}
	return (0);
}

static int		init_list(t_mlx *mlx, t_coords **elem, int fd)
{
	int		ret;
	char	*line;

	ret = 0;
	mlx->lines = 0;
	while ((ret = ft_read(fd, &line)) > 0)
	{
		if (vline(line) == 1
				|| (mlx->ppl = gvalues(elem, line, mlx->lines)) == -1)
		{
			if (line[0] == '\0')
				free(line);
			return (1);
		}
		mlx->lines++;
		if (line != NULL)
			free(line);
	}
	if (ret == -1)
		exit(error(ft_free(*elem)));
	return (0);
}

int				main(int ac, char **av)
{
	int			fd;
	t_mlx		mlx;
	t_coords	*elem;

	fd = open(av[1], O_RDONLY);
	elem = NULL;
	if (ac != 2 || fd < 0 || init_list(&mlx, &elem, fd) == 1)
		return (error(ft_free(elem)));
	if (mlx.lines == 0)
		return (error(1));
	close(fd);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIN_SIZE, WIN_SIZE, "fdf");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_SIZE, WIN_SIZE);
	mlx.img_data = mlx_get_data_addr(mlx.img_ptr, &mlx.bpp, &mlx.sl, &mlx.e);
	mlx.add_z = 1;
	new_img((mlx.elem = elem), &mlx, 0, av[1]);
	mlx_hook(mlx.win_ptr, 2, 0, mlx_key_press, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, mlx_leave, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
