/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:36:26 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/03 19:39:40 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	invalid_map_error(char *error_message)
{
	ft_putendl_fd(error_message, 2);
}

void	map_validator(char *map, t_map_d *map_d)
{
	char	*line;
	int		fd;
	int		row;

	row = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		perror(map);
	map_d->rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		map_d->rows++;
		printf ("->%s\n", line);
		if (row == 0)
			map_d->coloms = ft_strlen(line);
		if (row > 0 && ft_strlen(line) != map_d->coloms)
			invalid_map_error("Error: map is not rectangular");
		free (line);
		line = get_next_line(fd);
		row++;
	}
}
