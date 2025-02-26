/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:19:05 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/26 09:32:40 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_hook *hook)
{
	ft_putnbr_fd(hook->counter, 1);
	hook->counter++;
	if (hook->minf->grid[hook->minf->p_xy[1] - 1][hook->minf->p_xy[0]] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[hook->minf->p_xy[1] - 1][hook->minf->p_xy[0]] == 'E')
	{
		distroyer(hook);
		exit(0);
	}
	hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0]] = '0';
	hook->minf->grid[hook->minf->p_xy[1] - 1][hook->minf->p_xy[0]] = 'P';
	hook->minf->p_xy[1] -= 1;
}

void	right(t_hook *hook)
{
	ft_putnbr_fd(hook->counter, 1);
	hook->counter++;
	if (hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0] + 1] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0] + 1] == 'E')
	{
		distroyer(hook);
		exit(0);
	}
	hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0]] = '0';
	hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0] + 1] = 'P';
	hook->minf->p_xy[0] += 1;
}

void	left(t_hook *hook)
{
	ft_putnbr_fd(hook->counter, 1);
	hook->counter++;
	if (hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0] - 1] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0] - 1] == 'E')
	{
		distroyer(hook);
		exit(0);
	}
	hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0]] = '0';
	hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0] - 1] = 'P';
	hook->minf->p_xy[0] -= 1;
}
void	down(t_hook *hook)
{
	ft_putnbr_fd(hook->counter, 1);
	hook->counter++;
	if (hook->minf->grid[hook->minf->p_xy[1] + 1][hook->minf->p_xy[0]] == 'C')
		hook->minf->collectees--;
	else if (hook->minf->grid[hook->minf->p_xy[1] + 1][hook->minf->p_xy[0]] == 'E')
	{
		distroyer(hook);
		exit(0);
	}
	hook->minf->grid[hook->minf->p_xy[1]][hook->minf->p_xy[0]] = '0';
	hook->minf->grid[hook->minf->p_xy[1] + 1][hook->minf->p_xy[0]] = 'P';
	hook->minf->p_xy[1] += 1;
}
