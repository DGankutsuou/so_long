/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_puter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:30:46 by aabouriz          #+#    #+#             */
/*   Updated: 2025/03/01 14:36:49 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_puter(t_map *minf)
{
	int	x;
	int	y;

	y = 0;
	while (y < minf->rows)
	{
		x = 0;
		while (x < minf->coloms)
		{
			if (minf->grid[y][x] == '0')
			{
				if (minf->grid[y][x + 1] == '0' \
				&& minf->grid[y][x - 1] == '0' \
				&& minf->grid[y + 1][x] == '0' \
				&& minf->grid[y - 1][x] == '0')
				{
					minf->grid[y][x] = 'B';
				}
			}
			x++;
		}
		y++;
	}
}
