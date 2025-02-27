/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:43:59 by blessed           #+#    #+#             */
/*   Updated: 2025/02/27 08:59:55 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_things(t_things *thing, void *mlx)
{
	int	x;
	int	y;

	thing->wall = NULL;
	thing->ground = NULL;
	thing->clct = NULL;
	thing->ply = NULL;
	thing->exit = NULL;
	thing->wall = mlx_xpm_file_to_image(mlx, "textures/Wall.xpm", &x, &y);
	thing->ground = mlx_xpm_file_to_image(mlx, "textures/background.xpm", &x, &y);
	thing->clct = mlx_xpm_file_to_image(mlx, "textures/collect1.xpm", &x, &y);
	thing->ply = mlx_xpm_file_to_image(mlx, "textures/front_char1.xpm", &x, &y);
	thing->exit = mlx_xpm_file_to_image(mlx, "textures/exit.xpm", &x, &y);
}

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
	else if (key == 119 && hook->minf->grid[y - 1][x] != '1')
		up(hook);
	else if (key == 100 && hook->minf->grid[y][x + 1] != '1')
		right(hook);
	else if (key == 97 && hook->minf->grid[y][x - 1] != '1')
		left(hook);
	else if (key == 115 && hook->minf->grid[y + 1][x] != '1')
		down(hook);
	draw_things(hook->minf, hook->thing, hook->mlx, hook->win);
	return (0);
}

int	breath(t_hook *hook)
{
	int	x;
	int	y;

	//while (hook->sleeper < 2000000)
	hook->sleeper++;
	if (hook->sleeper == 20000)
	{
		if (hook->thing->clct != NULL)
			mlx_destroy_image(hook->mlx, hook->thing->clct);
		if (hook->thing->ply != NULL)
			mlx_destroy_image(hook->mlx, hook->thing->ply);
		hook->thing->ply = mlx_xpm_file_to_image(hook->mlx, hook->anime->mainp[hook->fram % 4], &x, &y);
		hook->thing->clct = mlx_xpm_file_to_image(hook->mlx, hook->anime->clc[hook->fram % 2], &x, &y);
		draw_things(hook->minf, hook->thing, hook->mlx, hook->win);
		hook->fram++;
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
	hook.fram = 0;
	hook.sleeper = 0;

	anime.mainp[0] = "textures/front_char1.xpm";
	anime.mainp[1] = "textures/front_char2.xpm";
	anime.mainp[2] = "textures/front_char3.xpm";
	anime.mainp[3] = "textures/front_char4.xpm";
	anime.clc[0] = "textures/collect1.xpm";
	anime.clc[1] = "textures/collect2.xpm";
	mlx_loop_hook(mlx, breath, &hook);
	mlx_key_hook(win, key_hook, &hook);
	//mlx_hook(win, 3, &hook)
	mlx_loop(mlx);
}
