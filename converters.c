/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:00:25 by jcreux            #+#    #+#             */
/*   Updated: 2019/06/09 11:01:51 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	char_hex_to_nb(char c)
{
	int		ret;

	ret = 0;
	if (c >= '0' && c <= '9')
		ret = c - 48;
	else if (c >= 'A' && c <= 'F')
		ret = c - 55;
	else if (c >= 'a' && c <= 'f')
		ret = c - 87;
	return (ret);
}

int			hex_to_dec(char *hex)
{
	return ((char_hex_to_nb(hex[0]) * 16) + char_hex_to_nb(hex[1]));
}

static char	nb_to_char_hex(int n)
{
	if (n >= 0 && n <= 9)
		return (n + 48);
	else
		return (n + 87);
}

static char	*dec_to_hex2(int n, int i, char *color)
{
	int		ret;
	int		rem;

	i += 1;
	ret = n;
	if (n == 0)
		color[i] = '0';
	if (n <= 15)
		color[i] = '0';
	while (ret != 0)
	{
		rem = ret % 16;
		ret = ret / 16;
		color[i--] = nb_to_char_hex(rem);
	}
	return (color);
}

char		*dec_to_hex(int red, int green, int blue)
{
	int		i;
	char	*color;

	i = 0;
	if (!(color = (char *)malloc(sizeof(char) * 9)))
		return (NULL);
	while (i < 2)
		color[i++] = '0';
	color = dec_to_hex2(red, i, color);
	color = dec_to_hex2(green, i + 2, color);
	color = dec_to_hex2(blue, i + 4, color);
	color[8] = '\0';
	return (color);
}
