#include "get_next_line.h"
#include "libft/libft.h"
#include "so_long.h"

static void	invalid_map_error(char *error_message)
{
	ft_putendl_fd(error_message, 2);
}

void	map_validator(char *map, t_map_d *map_d)
{
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	while (line = get_next_line(fd))
	{
		map_d->rows++;
		map_d->coloms = ft_strlen(line);
		free (line);
	}
}
