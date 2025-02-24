/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:43:59 by blessed           #+#    #+#             */
/*   Updated: 2025/02/24 18:08:55 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_starter(t_map *minf, t_things *thing)
{
	void	*mlx;
	void	*win;

	int w = 0;
	int h = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 16 * minf->coloms, 16 * minf->rows, "so_long");
	thing->wall = mlx_xpm_file_to_image(mlx, "things/Wall.xpm", &w, &h);
	for (int y = 0; y < minf->rows; y++)
	{
		for (int x = 0; x < minf->coloms; x++)
		{
			if (minf->grid[y][x] == '1')
				mlx_put_image_to_window(mlx, win, thing->wall, x * 16, y * 16);
		}
	}
	mlx_loop(mlx);
}
