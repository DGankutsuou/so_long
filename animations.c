/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:09:45 by aabouriz          #+#    #+#             */
/*   Updated: 2025/03/10 16:27:26 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clct_scared(t_hook *hook)
{
	int		x;
	int		y;
	char	*img;

	img = hook->anime->clc[hook->clct_frame % 2];
	if (hook->minf->collectees > 0)
	{
		mlx_destroy_image(hook->mlx, hook->thing->clct);
		hook->thing->clct = mlx_xpm_file_to_image(hook->mlx, img, &x, &y);
		draw_clct(hook);
		hook->clct_frame++;
	}
	hook->clct_sleeper = 0;
}

void	player_breath(t_hook *hook)
{
	int		x;
	int		y;
	char	*img;

	img = hook->anime->mainp[hook->player_frame % 4];
	mlx_destroy_image(hook->mlx, hook->thing->ply);
	hook->thing->ply = mlx_xpm_file_to_image(hook->mlx, img, &x, &y);
	draw_player(hook);
	hook->player_frame++;
	hook->player_sleeper = 0;
	draw_things(hook);
}

void	move_player(t_hook *hook)
{
	if (hook->anime->player_mv == 'U')
		up(hook);
	else if (hook->anime->player_mv == 'R')
		right(hook);
	else if (hook->anime->player_mv == 'L')
		left(hook);
	else if (hook->anime->player_mv == 'D')
		down(hook);
}

void	fire_animation(t_hook *hook)
{
	int		x;
	int		y;
	char	*img;

	img = hook->anime->firef[hook->fire_frame % 4];
	if (hook->minf->fire_counter > 0)
	{
		mlx_destroy_image(hook->mlx, hook->thing->fire);
		hook->thing->fire = mlx_xpm_file_to_image(hook->mlx, img, &x, &y);
		draw_fire(hook);
		hook->fire_frame++;
	}
	hook->fire_sleeper = 0;
}
