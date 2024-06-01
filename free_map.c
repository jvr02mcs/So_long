#include "so_long.h"

void	free_map(char **map, int f)
{
	size_t	l;

	l = 0;
	if (f == 1)
	{
		while (map[l])
		{
			free(map[l]);
			l++;
		}
	}
	free(map);
}
