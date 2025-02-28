/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:43:59 by blessed           #+#    #+#             */
/*   Updated: 2025/02/28 17:49:09 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	hook->clct_sleeper++;
	hook->player_sleeper++;
	hook->player_mv_sleeper++;
	if (hook->clct_sleeper == 20000)
	{
		if (!hook->anime->is_clct_mv && hook->minf->collectees > 0)
		{
			mlx_destroy_image(hook->mlx, hook->thing->clct);
			hook->thing->clct = mlx_xpm_file_to_image(hook->mlx, hook->anime->clc[hook->clct_frame % 2], &x, &y);
			draw_clct(hook);
			hook->clct_frame++;
			printf ("hi\n");
		}
		hook->clct_sleeper = 0;
	}
	if (!hook->anime->is_player_mv && hook->player_sleeper == 20300)
	{
		mlx_destroy_image(hook->mlx, hook->thing->ply);
		hook->thing->ply = mlx_xpm_file_to_image(hook->mlx, hook->anime->mainp[hook->player_frame % 4], &x, &y);
		draw_player(hook);
		hook->player_frame++;
		hook->player_sleeper = 0;
	}
	else if (hook->anime->is_player_mv && hook->player_mv_sleeper == 10000)
	{
		draw_things(hook);
		move_player(hook);
		hook->player_mv_sleeper = 0;
	}
	if (!hook->anime->is_player_mv)
		draw_things(hook);
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
	draw_all_things(minf, thing, mlx, win);
	hook.minf = minf;
	hook.thing = thing;
	hook.mlx = mlx;
	hook.win = win;
	hook.counter = 1;
	hook.anime = &anime;
	hook.clct_frame = 0;
	hook.clct_sleeper = 0;
	hook.player_frame = 0;
	hook.player_sleeper = 0;
	hook.player_mv_sleeper = 0;
	anime.is_zombie_mv = 0;
	init_player_frames(&anime);
	init_clct_frames(&anime);
	mlx_key_hook(win, key_hook, &hook);
	mlx_loop_hook(mlx, animation, &hook);
	//mlx_hook(win, 3, &hook)
	mlx_loop(mlx);
}
