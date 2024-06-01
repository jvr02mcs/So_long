#include "so_long.h"

size_t	count_lines(char **argv)
{
	char	*line;
	size_t	l;
	int		fd;

	fd = open(argv[1], O_RDONLY | 0644);
	if (!fd)
		return (-1);
	l = 0;
	line = get_next_line(fd);
	while (line)
	{
		l++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (l);
}
