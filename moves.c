/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:19:05 by aabouriz          #+#    #+#             */
/*   Updated: 2025/03/01 18:47:44 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_hook *hook)
{
	t_move		mv;
	static int	idx = 0;
	static int	growth = 0;

	mv.x = hook->minf->p_xy[0];
	mv.y = hook->minf->p_xy[1];
	hook->minf->grid[mv.y][mv.x] = '0';
	if (growth <= 64)
	{
		if (idx == 5)
			idx = 0;
		mv.pf = hook->anime->player_b[idx];
		mlx_destroy_image(hook->mlx, hook->thing->ply);
		hook->thing->ply = mlx_xpm_file_to_image(hook->mlx, mv.pf, \
		&mv.a, &mv.b);
		mlx_put_image_to_window(hook->mlx, hook->win, hook->thing->ply, \
		mv.x * 64, mv.y * 64 - growth);
		idx++;
		growth += SPEED;
	}
	else
		arive_u(hook, &idx, &growth);
}

void	right(t_hook *hook)
{
	t_move		mv;
	static int	idx = 0;
	static int	growth = 0;

	mv.x = hook->minf->p_xy[0];
	mv.y = hook->minf->p_xy[1];
	hook->minf->grid[mv.y][mv.x] = '0';
	if (growth <= 64)
	{
		if (idx == 5)
			idx = 0;
		mv.pf = hook->anime->player_r[idx];
		mlx_destroy_image(hook->mlx, hook->thing->ply);
		hook->thing->ply = mlx_xpm_file_to_image(hook->mlx, mv.pf, \
		&mv.a, &mv.b);
		mlx_put_image_to_window(hook->mlx, hook->win, hook->thing->ply, \
		mv.x * 64 + growth, mv.y * 64);
		idx++;
		growth += SPEED;
	}
	else
		arive_r(hook, &idx, &growth);
}

void	left(t_hook *hook)
{
	t_move		mv;
	static int	idx = 0;
	static int	growth = 0;

	mv.x = hook->minf->p_xy[0];
	mv.y = hook->minf->p_xy[1];
	hook->minf->grid[mv.y][mv.x] = '0';
	if (growth <= 64)
	{
		if (idx == 5)
			idx = 0;
		mv.pf = hook->anime->player_r[idx];
		mlx_destroy_image(hook->mlx, hook->thing->ply);
		hook->thing->ply = mlx_xpm_file_to_image(hook->mlx, mv.pf, \
		&mv.a, &mv.b);
		mlx_put_image_to_window(hook->mlx, hook->win, hook->thing->ply, \
		mv.x * 64 - growth, mv.y * 64);
		idx++;
		growth += SPEED;
	}
	else
		arive_l(hook, &idx, &growth);
}

void	down(t_hook *hook)
{
	t_move		mv;
	static int	idx = 0;
	static int	growth = 0;

	mv.x = hook->minf->p_xy[0];
	mv.y = hook->minf->p_xy[1];
	hook->minf->grid[mv.y][mv.x] = '0';
	if (growth <= 64)
	{
		if (idx == 5)
			idx = 0;
		mv.pf = hook->anime->player_r[idx];
		mlx_destroy_image(hook->mlx, hook->thing->ply);
		hook->thing->ply = mlx_xpm_file_to_image(hook->mlx, mv.pf, \
		&mv.a, &mv.b);
		mlx_put_image_to_window(hook->mlx, hook->win, hook->thing->ply, \
		mv.x * 64, mv.y * 64 + growth);
		idx++;
		growth += SPEED;
	}
	else
		arive_d(hook, &idx, &growth);
}
