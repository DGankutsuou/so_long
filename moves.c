/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:19:05 by aabouriz          #+#    #+#             */
/*   Updated: 2025/03/01 13:51:21 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_hook *hook)
{
	int			x;
	int			y;
	int			a;
	int			b;
	char		*pf;
	static int	idx = 0;
	static int	growth = 0;

	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	hook->minf->grid[y][x] = '0';
	if (growth <= 64)
	{
		if (idx == 5)
			idx = 0;
		pf = hook->anime->player_b[idx];
		mlx_destroy_image(hook->mlx, hook->thing->ply);
		hook->thing->ply = mlx_xpm_file_to_image(hook->mlx, pf, &a, &b);
		mlx_put_image_to_window(hook->mlx, hook->win, hook->thing->ply, x * 64, y * 64 - growth);
		idx++;
		growth += SPEED;
	}
	else
		arive_u(hook, &idx, &growth);
}

void	right(t_hook *hook)
{
	int			x;
	int			y;
	int			a;
	int			b;
	void		*pf;
	static int	idx = 0;
	static int	growth = 0;

	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	hook->minf->grid[y][x] = '0';
	if (growth <= 64)
	{
		if (idx == 5)
			idx = 0;
		pf = hook->anime->player_r[idx];
		mlx_destroy_image(hook->mlx, hook->thing->ply);
		hook->thing->ply = mlx_xpm_file_to_image(hook->mlx, pf, &a, &b);
		mlx_put_image_to_window(hook->mlx, hook->win, hook->thing->ply, x * 64 + growth, y * 64);
		idx++;
		growth += SPEED;
	}
	else
		arive_r(hook, &idx, &growth);
}

void	left(t_hook *hook)
{
	int			x;
	int			y;
	int			a;
	int			b;
	static int	idx = 0;
	static int	growth = 0;

	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	hook->minf->grid[y][x] = '0';
	if (growth <= 64)
	{
		if (idx == 5)
			idx = 0;
		mlx_destroy_image(hook->mlx, hook->thing->ply);
		hook->thing->ply = mlx_xpm_file_to_image(hook->mlx, hook->anime->player_l[idx], &a, &b);
		mlx_put_image_to_window(hook->mlx, hook->win, hook->thing->ply, x * 64 - growth, y * 64);
		idx++;
		growth += SPEED;
	}
	else
		arive_l(hook, &idx, &growth);
}

void	down(t_hook *hook)
{
	int			x;
	int			y;
	int			a;
	int			b;
	static int	idx = 0;
	static int	growth = 0;

	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	hook->minf->grid[y][x] = '0';
	if (growth <= 64)
	{
		if (idx == 5)
			idx = 0;
		mlx_destroy_image(hook->mlx, hook->thing->ply);
		hook->thing->ply = mlx_xpm_file_to_image(hook->mlx, hook->anime->player_f[idx], &a, &b);
		mlx_put_image_to_window(hook->mlx, hook->win, hook->thing->ply, x * 64, y * 64 + growth);
		idx++;
		growth += SPEED;
	}
	else
		arive_d(hook, &idx, &growth);
}
