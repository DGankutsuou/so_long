/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:43:59 by blessed           #+#    #+#             */
/*   Updated: 2025/02/27 20:32:03 by aabouriz         ###   ########.fr       */
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

int	key_hook(int key, t_hook *hook)
{
	int	x;
	int	y;

	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	if (key == 65307)
	{
		distroyer(hook);
		exit(0);
	}
	if (!hook->anime->is_player_mv)
	{
		hook->anime->is_player_mv = 1;
		if (key == U && hook->minf->grid[y - 1][x] != '1')
			hook->anime->player_mv = 'U';
		else if (key == R && hook->minf->grid[y][x + 1] != '1')
			hook->anime->player_mv = 'R';
		else if (key == L && hook->minf->grid[y][x - 1] != '1')
			hook->anime->player_mv = 'L';
		else if (key == D && hook->minf->grid[y + 1][x] != '1')
			hook->anime->player_mv = 'D';
		else
			hook->anime->is_player_mv = 0;
	}
	return (0);
}

int	animation(t_hook *hook)
{
	int	x;
	int	y;

	hook->sleeper++;
	if (hook->sleeper == 20000)
	{
		if (!hook->anime->is_clct_mv)
		{
			mlx_destroy_image(hook->mlx, hook->thing->clct);
			hook->thing->clct = mlx_xpm_file_to_image(hook->mlx, hook->anime->clc[hook->frame % 2], &x, &y);
		}
		if (!hook->anime->is_player_mv)
		{
			mlx_destroy_image(hook->mlx, hook->thing->ply);
			hook->thing->ply = mlx_xpm_file_to_image(hook->mlx, hook->anime->mainp[hook->frame % 4], &x, &y);
		}
		else
		{
			hook->anime->is_player_mv = 1;
			move_player(hook);
		}
		draw_things(hook->minf, hook->thing, hook->mlx, hook->win);
		hook->frame++;
		hook->sleeper = 0;
	}
	return (0);
}



void	game_starter(t_map *minf, t_things *thing)
{
	t_hook	hook;
	t_anime	anime;
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 64 * minf->coloms, 64 * minf->rows, "so_long");
	init_things(thing, mlx);
	draw_things(minf, thing, mlx, win);
	hook.minf = minf;
	hook.thing = thing;
	hook.mlx = mlx;
	hook.win = win;
	hook.counter = 1;
	hook.anime = &anime;
	hook.frame = 0;
	hook.sleeper = 0;
	anime.is_zombie_mv = 0;
	init_player_frames(&anime);
	init_clct_frames(&anime);
	mlx_key_hook(win, key_hook, &hook);
	mlx_loop_hook(mlx, animation, &hook);
	//mlx_hook(win, 3, &hook)
	mlx_loop(mlx);
}
