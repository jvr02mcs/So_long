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
		printf("\033[0;32mYou win!!!");
		close_win(sl);
	}
}
