/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:17:01 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/06/01 15:17:04 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	bad_char(char c)
{
	t_check	ch;

	ch.ocheck = '0' == c;
	ch.wcheck = '1' == c;
	ch.excheck = 'E' == c;
	ch.plyrcheck = 'P' == c;
	ch.ccheck = 'C' == c;
	if (ch.ocheck || ch.wcheck || ch.excheck)
		return (0);
	if (ch.plyrcheck || ch.ccheck)
		return (0);
	if (c == '\n')
		return (0);
	return (ft_error(4));
}

size_t	ft_howmany(char *m, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (m[i])
	{
		if (m[i++] == c)
			cnt++;
	}
	return (cnt);
}

int	count_chars(char **map)
{
	size_t		p;
	size_t		c;
	size_t		ex;
	size_t		i;

	p = 0;
	c = 0;
	ex = 0;
	i = 0;
	while (map[i])
	{
		p += ft_howmany(map[i], 'P');
		c += ft_howmany(map[i], 'C');
		ex += ft_howmany(map[i++], 'E');
	}
	if (p < 1 && c < 1 && ex < 1)
		return (ft_error(4));
	if (p < 1 || p > 1)
		return (ft_error(1));
	if (c < 1)
		return (ft_error(2));
	if (ex < 1 || ex > 1)
		return (ft_error(3));
	return (0);
}

int	good_chars(char *map_line)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(map_line);
	while (map_line[i])
	{
		if (bad_char(map_line[i]))
			return (0);
		if (map_line[i] != '\n' && i == len - 1)
		{
			ft_printf("\033[0;31mError:\033[0m invalid map struct\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	invalid_chars(char **map, size_t len)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (good_chars(map[i]))
			i++;
		else
			return (1);
	}
	if (invalid_walls(map, len))
		return (1);
	if (count_chars(map))
		return (1);
	return (0);
}
