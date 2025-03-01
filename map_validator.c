/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:36:26 by aabouriz          #+#    #+#             */
/*   Updated: 2025/03/01 14:30:02 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	validate_walls(t_map *map_inf)
{
	int	row;

	row = 0;
	while (row < map_inf->rows)
	{
		if (row == 0 || row == map_inf->rows - 1)
		{
			if (ft_strchar_cmp(map_inf->grid[row], '1') != 0)
			{
				free_map(map_inf->grid);
				error("Error\nmap is not surrounded by walls", 1);
			}
		}
		else if (map_inf->grid[row][0] != '1' || \
		map_inf->grid[row][map_inf->coloms - 1] != '1')
		{
			free_map(map_inf->grid);
			error("Error\nmap is not surrounded by walls", 1);
		}
		row++;
	}
}

static void	yx_counter(char *map, t_map *map_inf)
{
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		(perror(map), exit(1));
	map_inf->rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (map_inf->rows == 0)
			map_inf->coloms = ft_strlen(line) - 1;
		else if (ft_strlen(line) - 1 != (size_t)map_inf->coloms)
		{
			free(line);
			error("Error\nmap is not regtangular", 1);
		}
		map_inf->rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (map_inf->rows < 3)
		error("Error\nmap is not regtangular", 1);
}

static void	matrix_maker(int fd, t_map *map_inf)
{
	char	*line;
	int		row;

	map_inf->grid = malloc((map_inf->rows + 1) * 8);
	if (!map_inf->grid)
		error("Error\nmalloc() failed in matrix_maker()", 1);
	row = 0;
	while (row < map_inf->rows)
	{
		map_inf->grid[row] = malloc(map_inf->coloms + 1);
		if (!map_inf->grid[row])
		{
			while (--row > 0)
				free(map_inf->grid[row]);
			free(map_inf->grid);
			error("Error\nmalloc() failed in matrix_maker()", 1);
		}
		line = get_next_line(fd);
		ft_strlcpy(map_inf->grid[row], line, map_inf->coloms + 1);
		free(line);
		row++;
	}
	map_inf->grid[row] = NULL;
}

void	map_validator(char *map, t_map *map_inf)
{
	int		fd;

	if (ft_strlen(map) < 5)
		error("Error\ninvalid map file", 1);
	else if (ft_strncmp(map + ft_strlen(map) - 4, ".ber", 5) != 0)
		error("Error\ninvalid map file", 1);
	yx_counter(map, map_inf);
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		perror(map);
		exit (1);
	}
	matrix_maker(fd, map_inf);
	close(fd);
	validate_walls(map_inf);
	elements_validator(map_inf);
	enemy_puter(map_inf);
}
