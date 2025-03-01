/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:09:45 by aabouriz          #+#    #+#             */
/*   Updated: 2025/03/01 11:14:27 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clct_scared(t_hook *hook)
{
	int		x;
	int		y;
	int		is_pmv;
	char	*img;

	is_pmv = hook->anime->is_player_mv;
	img = hook->anime->clc[hook->clct_frame % 2];
	if (!is_pmv && !hook->anime->is_clct_mv && hook->minf->collectees > 0)
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
