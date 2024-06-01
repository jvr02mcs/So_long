/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:17:31 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/06/01 15:17:33 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_plyr_img(t_so_long sl, int f, size_t i, int l)
{
	if (f == 0)
		mlx_put_image_to_window(sl.mlx_ptr, sl.mlx_win, sl.imgs.p.imgs[0],
			32 * i, 32 * l);
	else if (f == 1)
		mlx_put_image_to_window(sl.mlx_ptr, sl.mlx_win, sl.imgs.p.imgs[1],
			32 * i, 32 * l);
	else if (f == 2)
		mlx_put_image_to_window(sl.mlx_ptr, sl.mlx_win, sl.imgs.p.imgs[2],
			32 * i, 32 * l);
	else if (f == 3)
		mlx_put_image_to_window(sl.mlx_ptr, sl.mlx_win, sl.imgs.p.imgs[3],
			32 * i, 32 * l);
}

void	putline(int l, t_so_long sl, int f)
{
	size_t	i;

	i = 0;
	while (sl.map[l][i])
	{
		if (sl.map[l][i] == '0')
			mlx_put_image_to_window(sl.mlx_ptr, sl.mlx_win, sl.imgs.f.img,
				32 * i, 32 * l);
		if (sl.map[l][i] == '1')
			mlx_put_image_to_window(sl.mlx_ptr, sl.mlx_win, sl.imgs.w.img,
				32 * i, 32 * l);
		if (sl.map[l][i] == 'P')
			put_plyr_img(sl, f, i, l);
		if (sl.map[l][i] == 'E')
			mlx_put_image_to_window(sl.mlx_ptr, sl.mlx_win, sl.imgs.ex.img,
				32 * i, 32 * l);
		if (sl.map[l][i] == 'C')
			mlx_put_image_to_window(sl.mlx_ptr, sl.mlx_win, sl.imgs.c.img,
				32 * i, 32 * l);
		if (sl.map[l][i] == 'G')
			mlx_put_image_to_window(sl.mlx_ptr, sl.mlx_win, sl.imgs.en.img,
				32 * i, 32 * l);
		i++;
	}
}
