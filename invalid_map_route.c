#include "so_long.h"

static t_map	*create_visited(int lns, int indx)
{
	t_map	*visited;
	int		i;

	visited = (t_map *)malloc(sizeof(t_map));
	visited->rows = lns;
	visited->cols = indx;
	visited->data = (bool **)malloc(lns * sizeof(bool *));
	i = 0;
	while (i < lns)
	{
		visited->data[i] = (bool *)ft_calloc(indx, sizeof(bool));
		i++;
	}
	return (visited);
}

static void	free_visited(t_map *visited)
{
	int	i;

	i = 0;
	while (i < visited->rows)
		free(visited->data[i++]);
	free(visited->data);
	free(visited);
}

static bool	dfs(char **map, int l, int i, t_map *visited)
{
	if (l < 0 || l >= visited->rows || i < 0 || i >= visited->cols
		|| map[l][i] == '1' || map[l][i] == 'G' || visited->data[l][i])
		return (false);
	visited->data[l][i] = (true);
	if (dfs(map, l + 1, i, visited) || dfs(map, l - 1, i, visited)
		|| dfs(map, l, i + 1, visited) || dfs(map, l, i - 1, visited))
		return (true);
	if (map[l][i] == 'E')
		return (true);
	return (false);
}

static bool	can_reach_exit(char **map, int l, int i, int lns)
{
	t_map	*visited;
	bool	result;
	int		cols;

	cols = ft_strlen(map[0]) - 1;
	visited = create_visited(lns, cols);
	result = dfs(map, l, i, visited);
	free_visited(visited);
	return (result);
}

int	invalid_map_route(char **map, int lns)
{
	int	l;
	int	i;

	l = 0;
	while (map[l])
	{
		i = 0;
		while (map[l][i] && map[l][i] != 'P')
			i++;
		if (map[l][i] == 'P')
			break ;
		l++;
	}
	if (can_reach_exit(map, l, i, lns))
		return (0);
	return (1);
}
