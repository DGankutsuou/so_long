/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:45:26 by aabouriz          #+#    #+#             */
/*   Updated: 2025/03/01 12:27:57 by aabouriz         ###   ########.fr       */
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
				mlx_put_image_to_window(mlx, win, thing->grd, x * 64, y * 64);
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

void	draw_player(t_hook *hook)
{
	int		x;
	int		y;
	void	*player;

	player = hook->thing->ply;
	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	mlx_put_image_to_window(hook->mlx, hook->win, player, x * 64, y * 64);
}

void	draw_clct(t_hook *hook)
{
	int		x;
	int		y;
	void	*c;
	void	*w;

	y = 0;
	c = hook->thing->clct;
	w = hook->win;
	while (y < hook->minf->rows)
	{
		x = 0;
		while (x < hook->minf->coloms)
		{
			if (hook->minf->grid[y][x] == 'C')
				mlx_put_image_to_window(hook->mlx, w, c, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	draw_things(t_hook *hook)
{
	int		x;
	int		y;
	void	*e;
	void	*g;
	void	*w;

	y = 0;
	e = hook->thing->exit;
	g = hook->thing->grd;
	w = hook->win;
	while (y < hook->minf->rows)
	{
		x = 0;
		while (x < hook->minf->coloms)
		{
			if (hook->minf->grid[y][x] == '0' || hook->minf->grid[y][x] == 'E')
				mlx_put_image_to_window(hook->mlx, w, g, x * 64, y * 64);
			if (hook->minf->collectees == 0 && hook->minf->grid[y][x] == 'E')
				mlx_put_image_to_window(hook->mlx, w, e, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
