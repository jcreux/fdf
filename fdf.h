/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:12:22 by jcreux            #+#    #+#             */
/*   Updated: 2019/06/10 16:58:04 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_SIZE	700
# define MID		350
# define LIM		175

/*
** declarations des structures
*/

typedef struct	s_coords
{
	int				abs;
	int				ord;
	int				alt;
	char			*color;
	struct s_coords	*next;
}				t_coords;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			sl;
	int			e;
	int			y;
	int			ppl;
	int			lines;
	t_coords	*elem;
	int			add_c;
	int			add_x;
	int			add_y;
	double		add_z;
	int			proj;
}				t_mlx;

typedef struct	s_ps
{
	int		c;
	int		x;
	int		y;
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	int		dx;
	int		dy;
	int		xinc;
	int		yinc;
	int		i;
	int		cumul;
}				t_ps;

typedef struct	s_counts
{
	int		i;
	int		j;
	int		abs;
}				t_counts;

/*
** prototypes des fonctions
*/

int				error(int i);
int				ft_read(int fd, char **line);
int				vline(char *s);
int				gvalues(t_coords **list, char *line, int ord);
char			*browse(t_counts *c, char *line);
void			new_img(t_coords *elem, t_mlx *mlx, int proj, char *title);
int				count_elem(t_coords *list);
char			*pseg(t_mlx *mlx, t_coords *a, t_coords *b, int proj);
t_ps			init_proj(t_mlx *mlx, t_coords a, t_coords b, int proj);
t_ps			iso(t_coords *a, t_coords *b);
t_ps			para(t_coords *a, t_coords *b);
int				hex_to_dec(char *hex);
char			*dec_to_hex(int red, int green, int blue);
int				mlx_leave(void *param);
int				ft_free(t_coords *elem);

#endif
