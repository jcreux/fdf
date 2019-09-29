/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:14:10 by jcreux            #+#    #+#             */
/*   Updated: 2019/06/10 19:22:35 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "fdf.h"

static char	*free_strjoin(char *tmp, char *buffer)
{
	char	*tmp2;

	tmp2 = ft_strjoin(tmp, buffer);
	free(tmp);
	return (tmp2);
}

int			ft_read(int fd, char **line)
{
	int		ret;
	char	buffer[2];
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * 1)))
		return (-1);
	tmp[0] = '\0';
	while ((ret = read(fd, buffer, 1)) > 0)
	{
		if (buffer[0] == '\0')
		{
			free(tmp);
			return (-1);
		}
		buffer[1] = '\0';
		if (buffer[0] == '\n' || !buffer[0])
		{
			*line = free_strjoin(tmp, buffer);
			return (1);
		}
		tmp = free_strjoin(tmp, buffer);
	}
	free(tmp);
	return (0);
}
