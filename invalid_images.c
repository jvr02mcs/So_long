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

int	invalid_images(void)
{
	int	fd;

	fd = open("./images/nothing.xpm", O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	fd = open("./images/wall.xpm", O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	fd = open("./images/coin.xpm", O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	fd = open("./images/exit.xpm", O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	fd = open("./images/enemy.xpm", O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}
