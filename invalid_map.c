/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:17:10 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/06/01 15:17:17 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	invalid_struct(char **map)
{
	size_t	len;
	int		i;

	i = 0;
	while (map[i])
	{
		len = 0;
		while (map[i][len])
			len++;
		if (len != ft_strlen(map[1]))
			return (1);
		i++;
	}
	return (0);
}

int	invalid_map(char **map, size_t len)
{
	if (invalid_struct(map))
	{
		ft_printf("\033[0;31mError:\033[0m invalid map struct\n");
		return (1);
	}
	if (invalid_chars(map, len))
		return (1);
	return (0);
}
