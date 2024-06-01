/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:16:33 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/06/01 15:16:39 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	count_lines(char **argv)
{
	char	*line;
	size_t	l;
	int		fd;

	fd = open(argv[1], O_RDONLY | 0644);
	if (!fd)
		return (-1);
	l = 0;
	line = get_next_line(fd);
	while (line)
	{
		l++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (l);
}
