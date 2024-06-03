/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:17:06 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/06/01 15:17:09 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	invalid_plyr_images(void)
{
	int	fd;

	fd = open("./textures/plyr.xpm", O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	fd = open("./textures/plyr_up.xpm", O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	fd = open("./textures/plyr_opo.xpm", O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	fd = open("./textures/plyr_down.xpm", O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

int	invalid_images(void)
{
	int	fd;

	if (invalid_plyr_images())
		return (1);
	fd = open("./textures/nothing.xpm", O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	fd = open("./textures/wall.xpm", O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	fd = open("./textures/coin.xpm", O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	fd = open("./textures/exit.xpm", O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	fd = open("./textures/enemy.xpm", O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}
