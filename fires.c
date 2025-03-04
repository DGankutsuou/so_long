/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fires.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blessed <blessed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 06:31:58 by blessed           #+#    #+#             */
/*   Updated: 2025/03/04 12:39:10 by blessed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count(t_map *map_inf)
{
	int	y;
	int	x;

	y = 1;
	map_inf->fire_counter = 0;
	while (y < map_inf->rows - 1)
	{
		x = 1;
		while (x < map_inf->coloms - 1)
		{
			if (map_inf->grid[y][x] == 'B')
				map_inf->fire_counter++;
			x++;
		}
		y++;
	}
}

static void	store(t_map *map_inf, t_fire *fire)
{
	int	y;
	int	x;
	int	fidx;

	y = 1;
	fidx = 0;
	while (y < map_inf->rows - 1)
	{
		x = 1;
		while (x < map_inf->coloms - 1)
		{
			if (map_inf->grid[y][x] == 'C')
			{
				fire[fidx].x = x;
				fire[fidx].y = y;
				fire[fidx++].is_mv = 0;
			}
			x++;
		}
		y++;
	}
}

int	store_fire(t_map *minf, t_fire **fire)
{
	count(minf);
	if (minf->fire_counter > 0)
		*fire = malloc(minf->fire_counter * sizeof(t_fire));
	if (!*fire)
		return (1);
	store(minf, *fire);
}
