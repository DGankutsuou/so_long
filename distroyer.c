/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:17:54 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/26 08:41:10 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	distroyer(t_hook *hook)
{
	free_map(hook->minf->grid);
	if (hook->thing->wall != NULL)
		mlx_destroy_image(hook->mlx, hook->thing->wall);
	if (hook->thing->ground != NULL)
		mlx_destroy_image(hook->mlx, hook->thing->ground);
	if (hook->thing->clct != NULL)
		mlx_destroy_image(hook->mlx, hook->thing->clct);
	if (hook->thing->ply != NULL)
		mlx_destroy_image(hook->mlx, hook->thing->ply);
	if (hook->thing->exit != NULL)
		mlx_destroy_image(hook->mlx, hook->thing->exit);
	mlx_destroy_window(hook->mlx, hook->win);
	mlx_destroy_display(hook->mlx);
	free(hook->mlx);
}
