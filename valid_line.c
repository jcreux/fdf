/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:39:31 by jcreux            #+#    #+#             */
/*   Updated: 2019/06/10 15:47:06 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	check_hexa_char(char *str, int rank)
{
	int		i;
	int		check1;
	int		check2;

	i = 0;
	check1 = -1;
	check2 = -1;
	while (i <= 8 && ft_ishexa(str[rank + i]) == 0)
		i++;
	if (str[rank + i] == ' ' || str[rank + i] == '\n')
		check1 = i;
	i = 0;
	while (i <= 8 && ft_ishexa(str[rank - i]) == 0)
		i++;
	if (str[rank - i] == 'x')
		check2 = i;
	if (check1 == -1 || check2 == -1 || check1 + check2 > 9)
		return (1);
	return (0);
}

static int	is_hexa_code(char *str, int rank)
{
	int		len_hc;

	len_hc = 0;
	while (ft_ishexa(str[rank++]) == 0 && len_hc <= 8)
		len_hc++;
	if (len_hc >= 1 && len_hc <= 8)
		return (0);
	return (1);
}

static int	valid_char(char c)
{
	if (ft_ishexa(c) == 0 || c == 'x' || c == ',' || c == ' ' || c == '-'
			|| c == '\n')
		return (0);
	return (1);
}

int			vline(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (valid_char(s[i]) == 1)
			return (1);
		else if (s[i] == '-'
				&& (ft_isdigit(s[i + 1]) == 0 || (s[i - 1] != ' ' && i != 0)))
			return (1);
		else if (s[i] == ',' && (s[i + 1] != '0' || s[i + 2] != 'x'
					|| ft_isdigit(s[i - 1]) == 0))
			return (1);
		else if (s[i] == 'x' && (s[i - 1] != '0' || s[i - 2] != ','
					|| is_hexa_code(s, i + 1) == 1))
			return (1);
		else if (s[i] >= 'a' && s[i] <= 'f' && check_hexa_char(s, i) == 1)
			return (1);
		i++;
	}
	return (0);
}
