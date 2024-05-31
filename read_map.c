#include "so_long.h"

char **make_map_arr(char **argv, int len)
{
    char **map;
    int i;
    int fd;

    i = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (NULL);
    map = malloc(sizeof(char *) * (len + 1));
	if (!map)
    {
        close(fd);
        return (NULL);
    }
    map[i] = get_next_line(fd);
    while (i < len && map[i])
    {
        i++;
        map[i] = get_next_line(fd);
    }
    map[len] = NULL;
    close(fd);
    return (map);
}

char **read_map(char **argv, int lns)
{
    char **map;

    map = make_map_arr(argv, lns);
    if (!map)
        return (NULL);

    if (invalid_map(map, lns))
    {
        free_map(map, 1);
        return (NULL);
    }

    return (map);
}
