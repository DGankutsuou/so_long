/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arives.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:38:17 by aabouriz          #+#    #+#             */
/*   Updated: 2025/03/01 15:32:00 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arive_r(t_hook *hook, int *idx, int *growth)
{
	int			x;
	int			y;

	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	ft_putstr_fd("-> ", 1);
	ft_putnbr_fd(hook->counter, 1);
	ft_putendl_fd("", 1);
	hook->counter++;
	if (x == hook->minf->e_xy[0] && y == hook->minf->e_xy[1])
		hook->minf->grid[y][x] = 'E';
	if (hook->minf->grid[y][x + 1] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[y][x + 1] == 'E')
	{
		if (hook->minf->collectees == 0)
			(distroyer(hook), exit(0));
	}
	else if (hook->minf->grid[y][x + 1] == 'B')
		(distroyer(hook), exit(0));
	hook->minf->grid[y][x + 1] = 'P';
	hook->minf->p_xy[0] += 1;
	hook->anime->is_player_mv = 0;
	*idx = 0;
	*growth = 0;
}

void	arive_l(t_hook *hook, int *idx, int *growth)
{
	int			x;
	int			y;

	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	ft_putstr_fd("-> ", 1);
	ft_putnbr_fd(hook->counter, 1);
	ft_putendl_fd("", 1);
	hook->counter++;
	if (x == hook->minf->e_xy[0] && y == hook->minf->e_xy[1])
		hook->minf->grid[y][x] = 'E';
	if (hook->minf->grid[y][x - 1] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[y][x - 1] == 'E')
	{
		if (hook->minf->collectees == 0)
			(distroyer(hook), exit(0));
	}
	else if (hook->minf->grid[y][x - 1] == 'B')
		(distroyer(hook), exit(0));
	hook->minf->grid[y][x - 1] = 'P';
	hook->minf->p_xy[0] -= 1;
	hook->anime->is_player_mv = 0;
	*idx = 0;
	*growth = 0;
}

void	arive_u(t_hook *hook, int *idx, int *growth)
{
	int			x;
	int			y;

	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	ft_putstr_fd("-> ", 1);
	ft_putnbr_fd(hook->counter, 1);
	ft_putendl_fd("", 1);
	hook->counter++;
	if (x == hook->minf->e_xy[0] && y == hook->minf->e_xy[1])
		hook->minf->grid[y][x] = 'E';
	if (hook->minf->grid[y - 1][x] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[y - 1][x] == 'E')
	{
		if (hook->minf->collectees == 0)
			(distroyer(hook), exit(0));
	}
	else if (hook->minf->grid[y - 1][x] == 'B')
		(distroyer(hook), exit(0));
	hook->minf->grid[y - 1][x] = 'P';
	hook->minf->p_xy[1] -= 1;
	hook->anime->is_player_mv = 0;
	*idx = 0;
	*growth = 0;
}

void	arive_d(t_hook *hook, int *idx, int *growth)
{
	int			x;
	int			y;

	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	ft_putstr_fd("-> ", 1);
	ft_putnbr_fd(hook->counter, 1);
	ft_putendl_fd("", 1);
	hook->counter++;
	if (x == hook->minf->e_xy[0] && y == hook->minf->e_xy[1])
		hook->minf->grid[y][x] = 'E';
	if (hook->minf->grid[y + 1][x] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[y + 1][x] == 'E')
	{
		if (hook->minf->collectees == 0)
			(distroyer(hook), exit(0));
	}
	else if (hook->minf->grid[y + 1][x] == 'B')
		(distroyer(hook), exit(0));
	hook->minf->grid[y + 1][x] = 'P';
	hook->minf->p_xy[1] += 1;
	hook->anime->is_player_mv = 0;
	*idx = 0;
	*growth = 0;
}
