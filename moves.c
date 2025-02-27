/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:19:05 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/27 19:12:02 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_hook *hook)
{
	int	x;
	int	y;

	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	ft_putstr_fd("-> ", 1);
	ft_putnbr_fd(hook->counter, 1);
	ft_putendl_fd("", 1);
	hook->counter++;
	hook->minf->grid[y][x] = '0';
	if (x == hook->minf->e_xy[0] && y == hook->minf->e_xy[1])
		hook->minf->grid[y][x] = 'E';
	if (hook->minf->grid[y - 1][x] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[y - 1][x] == 'E')
	{
		if (hook->minf->collectees == 0)
		{
			distroyer(hook);
			exit(0);
		}
	}
	hook->minf->grid[y - 1][x] = 'P';
	hook->minf->p_xy[1] -= 1;
}

void	right(t_hook *hook)
{
	int	x;
	int	y;

	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	ft_putstr_fd("-> ", 1);
	ft_putnbr_fd(hook->counter, 1);
	ft_putendl_fd("", 1);
	hook->counter++;
	hook->minf->grid[y][x] = '0';
	// for (int idx = 0, growth = 10; idx < 5; idx++)
	// {
	// 	mlx_destroy_image(hook->mlx, hook->thing->ply);
	// 	hook->thing->ply = mlx_xpm_file_to_image(hook->mlx, hook->anime->player_r[idx % 5], &x, &y);
	// 	mlx_put_image_to_window(hook->mlx, hook->win, hook->thing->ply, x * 64 + growth, y * 64);
	// 	growth += 10;
	// }
	if (x == hook->minf->e_xy[0] && y == hook->minf->e_xy[1])
		hook->minf->grid[y][x] = 'E';
	if (hook->minf->grid[y][x + 1] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[y][x + 1] == 'E')
	{
		if (hook->minf->collectees == 0)
		{
			distroyer(hook);
			exit(0);
		}
	}
	hook->minf->grid[y][x + 1] = 'P';
	hook->minf->p_xy[0] += 1;
}

void	left(t_hook *hook)
{
	int	x;
	int	y;

	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	ft_putstr_fd("-> ", 1);
	ft_putnbr_fd(hook->counter, 1);
	ft_putendl_fd("", 1);
	hook->counter++;
	hook->minf->grid[y][x] = '0';
	if (x == hook->minf->e_xy[0] && y == hook->minf->e_xy[1])
		hook->minf->grid[y][x] = 'E';
	if (hook->minf->grid[y][x - 1] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[y][x - 1] == 'E')
	{
		if (hook->minf->collectees == 0)
		{
			distroyer(hook);
			exit(0);
		}
	}
	hook->minf->grid[y][x - 1] = 'P';
	hook->minf->p_xy[0] -= 1;
}

void	down(t_hook *hook)
{
	int	x;
	int	y;

	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	ft_putstr_fd("-> ", 1);
	ft_putnbr_fd(hook->counter, 1);
	ft_putendl_fd("", 1);
	hook->counter++;
	hook->minf->grid[y][x] = '0';
	if (x == hook->minf->e_xy[0] && y == hook->minf->e_xy[1])
		hook->minf->grid[y][x] = 'E';
	if (hook->minf->grid[y + 1][x] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[y + 1][x] == 'E')
	{
		if (hook->minf->collectees == 0)
		{
			distroyer(hook);
			exit(0);
		}
	}
	hook->minf->grid[y + 1][x] = 'P';
	hook->minf->p_xy[1] += 1;
}
