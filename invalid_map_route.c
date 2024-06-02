#include "so_long.h"

// Crear la matriz de visitados
t_map	*create_visited(int rows, int cols)
{
	t_map	*visited;
	int		i;

	visited = (t_map *)malloc(sizeof(t_map));
	visited->rows = rows;
	visited->cols = cols;
	visited->data = (bool **)malloc(rows * sizeof(bool *));
	i = 0;
	while (i < rows)
	{
		visited->data[i] = (bool *)ft_calloc(cols, sizeof(bool));
		i++;
	}
	return (visited);
}

// Liberar la memoria de la matriz de visitados
void	free_visited(t_map *visited)
{
	int	i;

	i = 0;
	while (i < visited->rows)
		free(visited->data[i++]);
	free(visited->data);
	free(visited);
}

// Función DFS recursiva
bool	dfs(char **map, int l, int i, t_map *visited)
{
// Verificar si las coordenadas están fuera del mapa o si es una pared o ya está visitado
	if (l < 0 || l >= visited->rows || i < 0 || i >= visited->cols
		|| map[l][i] == '1' || visited->data[l][i])
		return (false);
// Si encontramos la salida
	if (map[l][i] == 'E')
		return (true);
// Marcar la celda actual como visitada
	visited->data[l][i] = (true);
// Moverse en las cuatro direcciones (arriba, abajo, izquierda, derecha)
	if (dfs(map, x + 1, y, visited) || dfs(map, x - 1, y, visited)
		|| dfs(map, x, y + 1, visited) || dfs(map, x, y - 1, visited))
		return (true);
	return (false);
}

// Función para verificar si el jugador puede llegar a la salida
bool	can_reach_exit(char **map, int l, int i, int lns)
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
