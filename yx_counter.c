/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yx_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:15:24 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/12 16:02:06 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	yx_counter(char *map, t_map *map_inf)
{
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		perror(map);
	map_inf->rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (map_inf->rows == 0)
			map_inf->coloms = ft_strlen(line) - 1;
		else if (ft_strlen(line) - 1 != map_inf->coloms)
			error("Error\nmap is not regtangular", 1);
		map_inf->rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (map_inf->rows < 3)
		error("Error\nmap is not regtangular", 1);
}
