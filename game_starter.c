/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:43:59 by blessed           #+#    #+#             */
/*   Updated: 2025/03/11 15:52:11 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exiter(t_hook *hook)
{
	distroyer(hook);
	exit(0);
	return (0);
}

int	key_hook(int key, t_hook *hook)
{
	int	x;
	int	y;

	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	if (key == 65307)
		(distroyer(hook), exit(0));
	if (!hook->anime->is_player_mv)
	{
		hook->anime->is_player_mv = 1;
		hook->player_mv_sleeper = 0;
		if ((key == U || key == AU) && hook->minf->grid[y - 1][x] != '1')
			hook->anime->player_mv = 'U';
		else if ((key == R || key == AR) && hook->minf->grid[y][x + 1] != '1')
			hook->anime->player_mv = 'R';
		else if ((key == L || key == AL) && hook->minf->grid[y][x - 1] != '1')
			hook->anime->player_mv = 'L';
		else if ((key == D || key == AD) && hook->minf->grid[y + 1][x] != '1')
			hook->anime->player_mv = 'D';
		else
			hook->anime->is_player_mv = 0;
	}
	return (0);
}

int	animation(t_hook *hook)
{
	hook->clct_sleeper++;
	hook->fire_sleeper++;
	hook->player_sleeper++;
	hook->player_mv_sleeper++;
	if (hook->clct_sleeper == 15000)
		clct_scared(hook);
	if (hook->fire_sleeper == 15000)
		fire_animation(hook);
	if (hook->timer == 30)
	{
		fire_everything(hook->minf);
		hook->timer = 0;
	}
	if (!hook->anime->is_player_mv && hook->player_sleeper == 20300)
		player_breath(hook);
	else if (hook->anime->is_player_mv && hook->player_mv_sleeper == 10000)
	{
		if (hook->minf->collectees > 0)
			clct_scared(hook);
		(draw_things(hook), move_player(hook));
		hook->player_mv_sleeper = 0;
		hook->player_sleeper = 0;
		hook->timer = 0;
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
	init_player_frames(&anime);
	init_clct_frames(&anime);
	init_enemy(&anime);
	hook.minf = minf;
	hook.thing = thing;
	hook.mlx = mlx;
	hook.win = win;
	hook.anime = &anime;
	init_hook(&hook);
	init_things(thing, mlx, &hook);
	draw_all_things(minf, thing, mlx, win);
	print_move(&hook);
	mlx_key_hook(win, key_hook, &hook);
	mlx_loop_hook(mlx, animation, &hook);
	mlx_hook(win, 17, 0, exiter, &hook);
	mlx_loop(mlx);
}
