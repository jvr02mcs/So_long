#include "so_long.h"

static char	**make_map_arr(int fd, int len)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (NULL);
	map[i] = get_next_line(fd);
	while (i < len && map[i])
	{
		i++;
		map[i] = get_next_line(fd);
	}
	map[len] = NULL;
	return (map);
}

char	**read_map(char **argv, int lns)
{
	char	**map;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_error(7);
		return (NULL);
	}
	map = make_map_arr(fd, lns);
	if (!map)
	{
		ft_printf("\033[0;31mError:\033[0m Can't create the map\n");
		return (NULL);
	}
	close(fd);
	if (invalid_map(map, lns))
	{
		free_map(map, 1);
		return (NULL);
	}
	return (map);
}
