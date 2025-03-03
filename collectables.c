/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectables.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blessed <blessed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 06:31:58 by blessed           #+#    #+#             */
/*   Updated: 2025/03/03 16:45:34 by blessed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



static void	store(t_map *map_inf, t_clct *clct, t_zombie *zombie)
{
	int	y;
	int	x;
	int	cidx;
	int	zidx;

	y = 1;
	cidx = 0;
	zidx = 0;
	map_inf->collectees = 0;
	map_inf->zombies = 0;
	while (y < map_inf->rows - 1)
	{
		x = 1;
		while (x < map_inf->coloms - 1)
		{
			if (map_inf->grid[y][x] == 'C')
			{
				clct[cidx].x = x;
				clct[cidx].y = y;
				clct[cidx++].is_mv = 0;
			}
			if (map_inf->grid[y][x] == 'Z')
			{
				zombie[zidx].x = x;
				zombie[zidx].y = y;
				zombie[zidx++].is_mv = 0;
				map_inf->zombies++;
			}
			x++;
		}
		y++;
	}
}

void	store_clcts(t_map *minf, t_clct **clcts)
{
	*clcts = malloc(minf->collectees * sizeof(t_clct));
	if (!*clcts)
	{
		free(minf->grid);
		exit(0);
	}
}
