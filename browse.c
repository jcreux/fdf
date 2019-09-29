/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:55:22 by jcreux            #+#    #+#             */
/*   Updated: 2019/06/10 16:57:13 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

char		*browse(t_counts *c, char *line)
{
	char	*alt;

	alt = ft_strnew(4);
	c->j = 0;
	while (line[c->i] == '-' || ft_isdigit(line[c->i]) == 1)
		alt[c->j++] = line[c->i++];
	alt[c->j] = '\0';
	return (alt);
}
