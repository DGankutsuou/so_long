/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:36:26 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/12 18:50:16 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static flood_fill()
{

}

static void	yx_counter(char *map, t_map *map_inf)
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

static void	matrix_maker(char *map, t_map *map_inf)
{
	char	*line;
	int		fd;
	int		row;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		perror(map);
	map_inf->grid = malloc((map_inf->rows + 1) * 8);
	if (!map_inf->grid)
		perror("malloc");
	row = 0;
	while (row < map_inf->rows)
	{
		map_inf->grid[row] = malloc(map_inf->coloms + 1);
		line = get_next_line(fd);
		ft_strlcpy(map_inf->grid[row], line, map_inf->coloms + 1);
		free(line);
		row++;
	}
	map_inf->grid[row] = NULL;
	close(fd);
}

void	map_validator(char *map, t_map *map_inf)
{
	char	*line;
	int		fd;
	int		row;

	if (ft_strlen(map) < 5)
		error("Error\ninvalid map file", 1);
	else if (ft_strncmp(map + ft_strlen(map) - 4, ".ber", 5) != 0)
		error("Error\ninvalid map file", 1);
	yx_counter(map, map_inf);
	matrix_maker(map, map_inf);
	row = 0;
	printf ("%d / %d\n", map_inf->rows, map_inf->coloms);
	while (row < map_inf->rows)
	{
		printf ("-> %s\n", (map_inf->grid)[row]);
		row++;
	}
	free_map(map_inf->grid);
}
