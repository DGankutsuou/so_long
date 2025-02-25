/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:43:59 by blessed           #+#    #+#             */
/*   Updated: 2025/02/25 15:32:50 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_things(t_map *minf, t_things *thing, void *mlx, void *win)
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
			else if (minf->grid[y][x] == '0')
				mlx_put_image_to_window(mlx, win, thing->ground, x * 64, y * 64);
			else if (minf->grid[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, thing->clct, x * 64, y * 64);
			else if (minf->grid[y][x] == 'P')
				mlx_put_image_to_window(mlx, win, thing->ply, x * 64, y * 64);
			else if (minf->grid[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, thing->exit, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	game_starter(t_map *minf, t_things *thing)
{
	void	*mlx;
	void	*win;

	int w = 0;
	int h = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 64 * minf->coloms, 64 * minf->rows, "so_long");
	thing->wall = mlx_xpm_file_to_image(mlx, "things/Wall.xpm", &w, &h);
	thing->ground = mlx_xpm_file_to_image(mlx, "things/background.xpm", &w, &h);
	thing->clct = mlx_xpm_file_to_image(mlx, "things/collect1.xpm", &w, &h);
	thing->ply = mlx_xpm_file_to_image(mlx, "things/front_char1.xpm", &w, &h);
	thing->exit = mlx_xpm_file_to_image(mlx, "things/exit.xpm", &w, &h);
	draw_things(minf, thing, mlx, win);
	mlx_loop(mlx);
}
