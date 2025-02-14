/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:20:49 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/14 15:09:53 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_maker(t_map *map_inf)
{
	int	y;

	y = 0;
	map_inf->grid_copy = (char **)malloc((map_inf->rows + 1) * 8);
	if (!map_inf->grid_copy)
		error("Error\nmalloc faild in copy_maker()", 1);
	while (y < map_inf->rows)
	{
		map_inf->grid_copy[y] = (char *)malloc(map_inf->coloms + 1);
		if (!map_inf->grid_copy[y])
		{
			while (--y > 0)
				free(map_inf->grid_copy[y]);
			free(map_inf->grid_copy);
			free_map(map_inf->grid);
		}
		ft_strlcpy(map_inf->grid_copy[y], map_inf->grid[y], \
		map_inf->coloms + 1);
		y++;
	}
	map_inf->grid_copy[y] = NULL;
}

static void	check_element(int y, int x, t_map *map_inf)
{
	if (map_inf->grid[y][x] == '0' || map_inf->grid[y][x] == '1')
		return ;
	else if (map_inf->grid[y][x] == 'C')
		map_inf->collectees++;
	else if (map_inf->grid[y][x] == 'P')
	{
		map_inf->p_xy[0] = x;
		map_inf->p_xy[1] = y;
		map_inf->player_counter++;
	}
	else if (map_inf->grid[y][x] == 'E')
	{
		map_inf->e_xy[0] = x;
		map_inf->e_xy[1] = y;
		map_inf->exit_counter++;
	}
	else
	{
		free_map(map_inf->grid);
		error("Error\ninvalid element in the map", 1);
	}
}

static void	count_elements(t_map *map_inf)
{
	int	y;
	int	x;

	y = 1;
	map_inf->collectees = 0;
	map_inf->player_counter = 0;
	map_inf->exit_counter = 0;
	while (y < map_inf->rows - 1)
	{
		x = 1;
		while (x < map_inf->coloms - 1)
		{
			check_element(y, x, map_inf);
			x++;
		}
		y++;
	}
}

static void	flood_fill(t_map *map, int x, int y)
{
	if (map->grid_copy[y][x] == '1' || map->grid_copy[y][x] == '.')
		return ;
	else if (map->grid_copy[y][x] == '0')
		map->grid_copy[y][x] = '.';
	else if (map->grid_copy[y][x] == 'E')
	{
		map->exit_counter--;
		map->grid_copy[y][x] = '.';
	}
	else if (map->grid_copy[y][x] == 'C')
	{
		map->grid_copy[y][x] = '.';
		map->collectees--;
	}
	else
		map->grid_copy[y][x] = '.';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	elements_validator(t_map *map_inf)
{
	count_elements(map_inf);
	if (map_inf->player_counter != 1 || map_inf->exit_counter != 1)
	{
		free_map(map_inf->grid);
		error("Error\nThere should be one player and one exit", 1);
	}
	else if (map_inf->collectees < 1)
	{
		free_map(map_inf->grid);
		error("Error\nThere should be at least one collectee", 1);
	}
	copy_maker(map_inf);
	flood_fill(map_inf, map_inf->p_xy[0], map_inf->p_xy[1]);
	if (map_inf->exit_counter != 0 || map_inf->collectees != 0)
	{
		free_map(map_inf->grid);
		free_map(map_inf->grid_copy);
		error("Error\nMap is not playable", 1);
	}
	free_map(map_inf->grid_copy);
}
