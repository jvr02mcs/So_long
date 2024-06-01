#include "so_long.h"

int	invalid_walls(char **map, size_t len)
{
	size_t	l;
	size_t	i;
	size_t	l_len;

	i = 0;
	l = 0;
	l_len = ft_strlen(map[0]) - 1;
	while (map[0][i] == '1' && map[len - 1][i] == '1')
		i++;
	if (i != l_len)
		return (ft_error(5));
	i = 0;
	while (map[l][0] == '1' && map[l][l_len - 1] == '1' && map[l + 1])
		l++;
	if (l != len - 1)
		return (ft_error(5));
	return (0);
}
