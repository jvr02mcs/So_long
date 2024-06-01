#include "./so_long.h"

int	close_win(t_so_long *sl)
{
	mlx_loop_end(sl->mlx_ptr);
	return (0);
}
