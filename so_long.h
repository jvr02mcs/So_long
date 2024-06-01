#ifndef SO_LONG_H
# define SO_LONG_H
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_obj
{
	int	o;
	int	w;
	int	ex;
	int	p;
	int	c;
}	t_obj;

typedef struct s_check
{
	bool	ocheck;
	bool	wcheck;
	bool	excheck;
	bool	plyrcheck;
	bool	ccheck;
	bool	encheck;
}	t_check;

typedef struct s_image
{
	void	*img;
	char	*path;
	void	*imgs[3];
	int		w;
	int		h;
}	t_image;

typedef struct s_images
{
	t_image		f;
	t_image		p;
	t_image		w;
	t_image		ex;
	t_image		c;
	t_image		en;
}	t_images;

typedef struct s_so_long
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		**map;
	int			moves;
	size_t		lns;
	t_images	imgs;
}	t_so_long;

int invalid_map_route(char **map, int lens);
int		close_win(t_so_long *sl);
void	move(t_so_long *sl, int lns, int indx, int f);
void	free_map(char **map, int f);
int		ft_error(int f);
void	init_game_win(t_so_long *sl);
void	putline(int l, t_so_long sl, int f);
int		invalid_args(int argc, char **argv);
int		invalid_walls(char **map, size_t len);
int		invalid_chars(char **map, size_t len);
int		invalid_map(char **map, size_t len);
int		invalid_images(void);
size_t	count_lines(char **argv);
char	**read_map(char **argv, int lns);

#endif