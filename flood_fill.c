/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:50:59 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/13 09:35:54 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *map, int x, int y)
{
	if(map->grid[y][x] == '0')
	else if(map->grid[y][x] == '1')
		return ;
	else if(map->grid[y][x] == 'E')
	else if(map->grid[y][x] == 'C')
	else
	{
		free_map(map->grid);
		error("Error\nmap must only containe: 0, 1, P, C, E");
	}
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
