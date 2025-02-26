/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:19:05 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/26 10:35:24 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_hook *hook)
{
	ft_putstr_fd("-> ", 1);
	ft_putnbr_fd(hook->counter, 1);
	ft_putendl_fd("", 1);
	hook->counter++;
	hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0]] = '0';
	if (hook->minf->p_xy[0] == hook->minf->e_xy[0] && hook->minf->p_xy[1] == hook->minf->e_xy[1])
		hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0]] = 'E';
	if (hook->minf->grid[hook->minf->p_xy[1] - 1][hook->minf->p_xy[0]] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[hook->minf->p_xy[1] - 1][hook->minf->p_xy[0]] == 'E')
	{
		if (hook->minf->collectees == 0)
		{
			distroyer(hook);
			exit(0);
		}
	}
	hook->minf->grid[hook->minf->p_xy[1] - 1][hook->minf->p_xy[0]] = 'P';
	hook->minf->p_xy[1] -= 1;
}

void	right(t_hook *hook)
{
	ft_putstr_fd("-> ", 1);
	ft_putnbr_fd(hook->counter, 1);
	ft_putendl_fd("", 1);
	hook->counter++;
	hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0]] = '0';
	if (hook->minf->p_xy[0] == hook->minf->e_xy[0] && hook->minf->p_xy[1] == hook->minf->e_xy[1])
		hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0]] = 'E';
	if (hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0] + 1] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0] + 1] == 'E')
	{
		if (hook->minf->collectees == 0)
		{
			distroyer(hook);
			exit(0);
		}
	}
	hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0] + 1] = 'P';
	hook->minf->p_xy[0] += 1;
}

void	left(t_hook *hook)
{
	ft_putstr_fd("-> ", 1);
	ft_putnbr_fd(hook->counter, 1);
	ft_putendl_fd("", 1);
	hook->counter++;
	hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0]] = '0';
	if (hook->minf->p_xy[0] == hook->minf->e_xy[0] && hook->minf->p_xy[1] == hook->minf->e_xy[1])
		hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0]] = 'E';
	if (hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0] - 1] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0] - 1] == 'E')
	{
		if (hook->minf->collectees == 0)
		{
			distroyer(hook);
			exit(0);
		}
	}
	hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0] - 1] = 'P';
	hook->minf->p_xy[0] -= 1;
}
void	down(t_hook *hook)
{
	ft_putstr_fd("-> ", 1);
	ft_putnbr_fd(hook->counter, 1);
	ft_putendl_fd("", 1);
	hook->counter++;
	hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0]] = '0';
	if (hook->minf->p_xy[0] == hook->minf->e_xy[0] && hook->minf->p_xy[1] == hook->minf->e_xy[1])
		hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0]] = 'E';
	if (hook->minf->grid[hook->minf->p_xy[1] + 1][hook->minf->p_xy[0]] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[hook->minf->p_xy[1] + 1][hook->minf->p_xy[0]] == 'E')
	{
		if (hook->minf->collectees == 0)
		{
			distroyer(hook);
			exit(0);
		}
	}
	hook->minf->grid[hook->minf->p_xy[1] + 1][hook->minf->p_xy[0]] = 'P';
	hook->minf->p_xy[1] += 1;
}
