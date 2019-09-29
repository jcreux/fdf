/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:22:38 by jcreux            #+#    #+#             */
/*   Updated: 2019/06/10 19:26:07 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft/libft.h"

static t_coords	*append(t_coords **list, t_coords *item)
{
	t_coords	*elem;

	if (!(*list))
	{
		*list = item;
		return (*list);
	}
	elem = *list;
	while (elem && elem->next)
		elem = elem->next;
	elem->next = item;
	return (elem->next);
}

static char		*gcolor(char *line, int rank)
{
	int		i;
	int		len;
	int		init_rank;
	char	*color;

	i = 0;
	len = 0;
	init_rank = rank;
	if (!(color = (char *)malloc(sizeof(char) * 9)))
		return (NULL);
	while (ft_ishexa(line[rank++]) == 0)
		len++;
	while (len < 8)
	{
		color[i++] = '0';
		len++;
	}
	while (ft_ishexa(line[init_rank]) == 0)
		color[i++] = line[init_rank++];
	color[i] = '\0';
	return (color);
}

static t_coords	*create(int abs, int ord, int alt, char *color)
{
	t_coords	*item;

	if (!(item = (t_coords *)malloc(sizeof(t_coords))))
		return (NULL);
	item->abs = abs;
	item->ord = ord;
	item->alt = alt;
	item->color = color;
	item->next = NULL;
	return (item);
}

static void		create_list(t_coords **list, t_counts *c, char *line, int ord)
{
	char			*alt;
	t_coords		*n;
	static t_coords	*last_elem = NULL;

	if (line[c->i] == '-' || ft_isdigit(line[c->i]) == 1)
	{
		alt = browse(c, line);
		if ((ft_strlen(alt) == 10 && alt[0] == '-') || (ft_strlen(alt) <= 9))
		{
			if (line[c->i] == ',')
			{
				n = create(c->abs++, ord, ft_atoi(alt), gcolor(line, c->i + 3));
				while (line[c->i] != ' ' && line[c->i] != '\n')
					c->i++;
			}
			else
				n = create(c->abs++, ord, ft_atoi(alt), ft_strdup("00ffffff"));
			(last_elem == NULL) ? append(list, n) : append(&last_elem, n);
		}
		else if (line[0] != '\0')
			exit(error(ft_free(*list)));
		free(alt);
	}
	else
		c->i++;
}

int				gvalues(t_coords **list, char *line, int ord)
{
	t_counts	c;
	static int	init_abs = -1;

	c.i = 0;
	c.abs = 0;
	while (line[c.i] != '\n')
		create_list(list, &c, line, ord);
	if (init_abs == -1)
		init_abs = c.abs;
	else if (init_abs != c.abs)
		return (-1);
	return (init_abs);
}
