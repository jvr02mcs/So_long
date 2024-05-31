#include "so_long.h"

int	invalid_struct(char **map)
{
	size_t	len;
	int		i;

	i = 0;
	while (map[i])
	{
		len = 0;
		while (map[i][len])
			len++;
		if (len != ft_strlen(map[1]))
			return (1);
		i++;
	}
	return (0);
}

int	invalid_map(char **map, size_t len)
{
	if (invalid_struct(map))
	{
		printf("\033[0;31mError:\033[0m invalid map struct\n");
		return (1);
	}
	if (invalid_chars(map, len))
		return (1);
	return (0);
}
