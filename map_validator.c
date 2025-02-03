/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:36:26 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/03 18:36:27 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		row;

	row = 0;
	fd = open(map, O_RDONLY);
	map_d->rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		map_d->rows++;
		if (row == 0)
			map_d->coloms = ft_strlen(line);
		free (line);
		line = get_next_line(fd);
		row++;
	}
}
