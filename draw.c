/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:45:26 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/27 21:00:12 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_all_things(t_map *minf, t_things *thing, void *mlx, void *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < minf->rows)
	{
		x = 0;
		while (x < minf->coloms)
		{
			if (minf->grid[y][x] == '1')
				mlx_put_image_to_window(mlx, win, thing->wall, x * 64, y * 64);
			else if (minf->grid[y][x] == '0' || minf->grid[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, thing->ground, x * 64, y * 64);
			else if (minf->grid[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, thing->clct, x * 64, y * 64);
			else if (minf->grid[y][x] == 'P')
				mlx_put_image_to_window(mlx, win, thing->ply, x * 64, y * 64);
			if (minf->collectees == 0 && minf->grid[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, thing->exit, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	draw_player(t_map *minf, t_things *thing, void *mlx, void *win)
{
	int	x;
	int	y;

	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	mlx_put_image_to_window(mlx, win, thing->ply, x * 64, y * 64);
}

void	draw_clct(t_map *minf, t_things *thing, void *mlx, void *win)
{
	int	x;
	int	y;

	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	mlx_put_image_to_window(mlx, win, thing->ply, x * 64, y * 64);
}
