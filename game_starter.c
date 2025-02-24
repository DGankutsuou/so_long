/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:43:59 by blessed           #+#    #+#             */
/*   Updated: 2025/02/24 16:48:27 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_starter(t_map *minf, t_things *thing)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 32 * minf->coloms, 32 * minf->rows, "so_long");
	thing->wall = mlx_xpm_file_to_image(mlx, "things/Wall.xpm", win, win);
	for (int y = 0; y < minf->rows; y++)
	{
		for (int x = 0; x < minf->coloms; x++)
		{
			if (minf->grid[y][x] == '1')
				mlx_put_image_to_window(mlx, win, thing->wall, x * 32, y * 32);
		}
	}
	mlx_loop(mlx);
}
