/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 04:20:27 by jcreux            #+#    #+#             */
/*   Updated: 2018/12/16 17:04:02 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}
