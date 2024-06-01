#include "so_long.h"

static int	u_can_win_da_game(char **map)
{
	size_t	l;

	l = 0;
	while (map[l])
	{
		if (ft_strrchr(map[l], 'C') != NULL)
			return (0);
		l++;
	}
	return (1);
}

void	aux_for_move(t_so_long *sl, int l, int lns, int f)
{
	putline(l, *sl, f);
	putline(l + lns, *sl, f);
}

void	move_default(t_so_long *sl, int lns, int indx, int f)
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
			break ;
		l++;
	}
	sl->moves++;
	sl->map[l][i] = '0';
	ft_printf("-%d- moves\n", sl->moves);
	if (f == 24)
	{
		ft_printf("\033[0;32mYou win!!!\033[0m\n");
		close_win(sl);
	}
	sl->map[l + lns][i + indx] = 'P';
	aux_for_move(sl, l, lns, f);
}

void	move(t_so_long *sl, int lns, int indx, int f)
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
			break ;
		l++;
	}
	if (sl->map[l + lns][i + indx] == '0' || sl->map[l + lns][i + indx] == 'C')
		move_default(sl, lns, indx, f);
	else if (sl->map[l + lns][i + indx] == 'G')
	{
		sl->map[l][i] = 'G';
		sl->map[l + lns][i + indx] = '0';
		aux_for_move(sl, l, lns, f);
		ft_printf("\033[0;31mYou lost!!!\033[0m\n");
		close_win(sl);
	}
	else if (sl->map[l + lns][i + indx] == 'E' && u_can_win_da_game(sl->map))
		move_default(sl, lns, indx, 24);
}
