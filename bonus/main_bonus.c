#include "./so_long.h"

int	close_win(t_so_long *sl)
{
	mlx_loop_end(sl->mlx_ptr);
	return (0);
}

int	u_can_win_da_game(char **map)
{
	size_t	l;

	l = 0;
	while (map[l])
	{
		if (ft_strrchr(map[l], 'C') != NULL)
			return(0);
		l++;
	}
	return (1);
}

void move(t_so_long *sl, int lns, int indx, int f)
{
	int	l;
	int	i;

	l = 0;
	while (sl->map[l])
	{
		i = 0;
		while (sl->map[l][i] && sl->map[l][i] != 'P')
			i++;
		if (sl->map[l][i] == 'P')
			break;
		l++;
	}
	if (sl->map[l + lns][i + indx] == '0' || sl->map[l + lns][i + indx] == 'C')
	{
		sl->moves++;
		sl->map[l][i] = '0';
		sl->map[l + lns][i + indx] = 'P';
		putline(l, *sl, f);
		putline(l + lns, *sl, f);
		printf("-%d- moves\n", sl->moves);
	}
	else if (sl->map[l + lns][i + indx] == 'E' && u_can_win_da_game(sl->map))
	{
		sl->moves++;
		sl->map[l][i] = '0';
		sl->map[l + lns][i + indx] = 'P';
		putline(l, *sl, f);
		putline(l + lns, *sl, f);
		close_win(sl);
	}
}

int	handle(int key, t_so_long *sl)
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
void	free_resources(t_so_long *sl)
{
	int	i;

	i = 0;
	while (i <= 3)
		mlx_destroy_image(sl->mlx_ptr, sl->imgs.p.imgs[i++]);
	if (sl->imgs.p.img)
		mlx_destroy_image(sl->mlx_ptr, sl->imgs.p.img);
	if (sl->imgs.f.img)
		mlx_destroy_image(sl->mlx_ptr, sl->imgs.f.img);
	if (sl->imgs.w.img)
		mlx_destroy_image(sl->mlx_ptr, sl->imgs.w.img);
	if (sl->imgs.en.img)
		mlx_destroy_image(sl->mlx_ptr, sl->imgs.en.img);
	if (sl->imgs.c.img)
		mlx_destroy_image(sl->mlx_ptr, sl->imgs.c.img);
	if (sl->imgs.ex.img)
		mlx_destroy_image(sl->mlx_ptr, sl->imgs.ex.img);
	//if (sl->imgs.en.img)
	//	mlx_destroy_image(sl->mlx_ptr, sl->imgs.en.img);
	if (sl->mlx_win)
		mlx_destroy_window(sl->mlx_ptr, sl->mlx_win);
	if (sl->mlx_ptr)
	{
		mlx_destroy_display(sl->mlx_ptr);
		free(sl->mlx_ptr);
	}
	if (sl->map)
		free_map(sl->map, NULL, 1);
}

void	put_images_to_window(t_so_long sl)
{
	size_t	l;

	l = 0;
	while (sl.map[l])
	{
		putline(l, sl, 0);
		l++;
	}
	printf("\n-%d- moves\n", 0);
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
	free_resources(&sl);
	return (0);
}
