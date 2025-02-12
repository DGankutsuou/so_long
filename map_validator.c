/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:36:26 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/12 16:40:35 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_validator(char *map, t_map *map_inf)
{
	char	*line;
	int		fd;
	int		row;

	if(ft_strlen(map) < 5)
		error("Error\ninvalid map file", 1);
	else if (ft_strncmp(map + ft_strlen(map) - 4, ".ber", 5) != 0)
		error("Error\ninvalid map file", 1);
	yx_counter(map, map_inf);
	matrix_maker
	fd = open(map, O_RDONLY);
	if (fd < 0)
		perror(map);
	map_inf->rows = 0;
	line = get_next_line(fd);
	while (line)
	{

	}
}
