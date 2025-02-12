/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_macker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:44:37 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/12 15:15:25 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	matrix_macker(char *map, t_map *map_inf)
{
	char	*line;
	int		fd;
	int		row;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		perror(map);
	map_inf->grid = malloc(map_inf->coloms + 1);
	if (!map_inf->grid)
		perror("malloc");
	row = 0;
	while (row < map_inf->rows)
	{
		ft_strlcpy()
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
