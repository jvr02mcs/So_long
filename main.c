/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:17:24 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/06/01 15:17:26 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static int	handle(int key, t_so_long *sl)
{
	if (key == XK_Escape)
		return (close_win(sl));
	if (key == XK_w || key == XK_Up)
		move(sl, -1, 0, 1);
	if (key == XK_s || key == XK_Down)
		move(sl, 1, 0, 2);
	if (key == XK_d || key == XK_Right)
		move(sl, 0, 1, 0);
	if (key == XK_a || key == XK_Left)
		move(sl, 0, -1, 3);
	return (0);
}

static void	free_resources(t_so_long *sl, int i)
{
	while (i <= 3)
		mlx_destroy_image(sl->mlx_ptr, sl->imgs.p.imgs[i++]);
	if (sl->imgs.p.img)
		mlx_destroy_image(sl->mlx_ptr, sl->imgs.p.img);
	if (sl->imgs.f.img)
		mlx_destroy_image(sl->mlx_ptr, sl->imgs.f.img);
	if (sl->imgs.w.img)
		mlx_destroy_image(sl->mlx_ptr, sl->imgs.w.img);
	if (sl->imgs.c.img)
		mlx_destroy_image(sl->mlx_ptr, sl->imgs.c.img);
	if (sl->imgs.ex.img)
		mlx_destroy_image(sl->mlx_ptr, sl->imgs.ex.img);
	if (sl->imgs.en.img)
		mlx_destroy_image(sl->mlx_ptr, sl->imgs.en.img);
	if (sl->mlx_win)
		mlx_destroy_window(sl->mlx_ptr, sl->mlx_win);
	if (sl->mlx_ptr)
	{
		mlx_destroy_display(sl->mlx_ptr);
		free(sl->mlx_ptr);
	}
	if (sl->map)
		free_map(sl->map, 1);
}

static void	put_images_to_window(t_so_long sl)
{
	size_t	l;

	l = 0;
	while (sl.map[l])
	{
		putline(l, sl, 0);
		l++;
	}
	ft_printf("\n-%d- moves\n", 0);
}

int	main(int argc, char **argv)
{
	t_so_long	sl;

	ft_bzero(&sl, sizeof(t_so_long));
	sl.moves = 0;
	sl.mlx_ptr = NULL;
	sl.mlx_win = NULL;
	if (invalid_args(argc, argv))
		return (1);
	sl.lns = count_lines(argv);
	sl.map = read_map(argv, sl.lns);
	if (!sl.map)
		return (1);
	init_game_win(&sl);
	put_images_to_window(sl);
	mlx_key_hook(sl.mlx_win, handle, &sl);
	mlx_hook(sl.mlx_win, 17, 0, close_win, &sl);
	mlx_loop(sl.mlx_ptr);
	free_resources(&sl, 0);
	return (0);
}
