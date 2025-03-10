/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arives.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:38:17 by aabouriz          #+#    #+#             */
/*   Updated: 2025/03/10 17:28:28 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(t_hook *hook)
{
	char	*move;
	char	*number;
	void	*wall;

	number = ft_itoa(hook->counter);
	move = ft_strjoin("move: ", number);
	wall = hook->thing->wall;
	mlx_put_image_to_window(hook->mlx, hook->win, wall, 64, 0);
	mlx_string_put(hook->mlx, hook->win, 32, 32, 0xFFFFFF, move);
	free(number);
	free(move);
	hook->counter++;
}

void	arive_r(t_hook *hook, int *idx, int *growth)
{
	int			x;
	int			y;

	x = hook->minf->p_xy[0];
	y = hook->minf->p_xy[1];
	print_move(hook);
	if (x == hook->minf->e_xy[0] && y == hook->minf->e_xy[1])
		hook->minf->grid[y][x] = 'E';
	if (hook->minf->grid[y][x + 1] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[y][x + 1] == 'E')
	{
		if (hook->minf->collectees == 0)
			(ft_putendl_fd("Thou art winner", 1), distroyer(hook), exit(0));
	}
	else if (hook->minf->grid[y][x + 1] == 'F')
		(ft_putendl_fd("Thou art looser", 1), distroyer(hook), exit(0));
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
	print_move(hook);
	if (x == hook->minf->e_xy[0] && y == hook->minf->e_xy[1])
		hook->minf->grid[y][x] = 'E';
	if (hook->minf->grid[y][x - 1] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[y][x - 1] == 'E')
	{
		if (hook->minf->collectees == 0)
			(ft_putendl_fd("Thou art winner", 1), distroyer(hook), exit(0));
	}
	else if (hook->minf->grid[y][x - 1] == 'F')
		(ft_putendl_fd("Thou art looser", 1), distroyer(hook), exit(0));
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
	print_move(hook);
	if (x == hook->minf->e_xy[0] && y == hook->minf->e_xy[1])
		hook->minf->grid[y][x] = 'E';
	if (hook->minf->grid[y - 1][x] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[y - 1][x] == 'E')
	{
		if (hook->minf->collectees == 0)
			(ft_putendl_fd("Thou art winner", 1), distroyer(hook), exit(0));
	}
	else if (hook->minf->grid[y - 1][x] == 'F')
		(ft_putendl_fd("Thou art looser", 1), distroyer(hook), exit(0));
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
	print_move(hook);
	if (x == hook->minf->e_xy[0] && y == hook->minf->e_xy[1])
		hook->minf->grid[y][x] = 'E';
	if (hook->minf->grid[y + 1][x] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[y + 1][x] == 'E')
	{
		if (hook->minf->collectees == 0)
			(ft_putendl_fd("Thou art winner", 1), distroyer(hook), exit(0));
	}
	else if (hook->minf->grid[y + 1][x] == 'F')
		(ft_putendl_fd("Thou art looser", 1), distroyer(hook), exit(0));
	hook->minf->grid[y + 1][x] = 'P';
	hook->minf->p_xy[1] += 1;
	hook->anime->is_player_mv = 0;
	*idx = 0;
	*growth = 0;
}
