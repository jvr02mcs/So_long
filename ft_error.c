#include "so_long.h"

int	ft_error(int f)
{
	printf("\033[0;31mError:\033[0m ");
	if (f == 1)
		return (printf("There must be at least one player and only one.\n"));
	if (f == 2)
		return (printf("There must be at least one coin.\n"));
	if (f == 3)
		return (printf("What you gonna do...?\n"));
	if (f == 4)
		return (printf("You don't give a damn\n"));
	if (f == 5)
		return (printf("Your fly is down... Check the walls\n"));
	if (f == 6)
		return (printf("Use 'make bonus' to use this map\n"));
	return (1);
}

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
