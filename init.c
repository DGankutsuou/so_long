/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:18:49 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/27 14:35:25 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_things(t_things *thing, void *mlx)
{
	int	x;
	int	y;

	thing->wall = NULL;
	thing->ground = NULL;
	thing->clct = NULL;
	thing->ply = NULL;
	thing->exit = NULL;
	thing->wall = mlx_xpm_file_to_image(mlx, "textures/Wall.xpm", &x, &y);
	thing->ground = mlx_xpm_file_to_image(mlx, "textures/background.xpm", &x, &y);
	thing->clct = mlx_xpm_file_to_image(mlx, "textures/collect1.xpm", &x, &y);
	thing->ply = mlx_xpm_file_to_image(mlx, "textures/front_char1.xpm", &x, &y);
	thing->exit = mlx_xpm_file_to_image(mlx, "textures/exit.xpm", &x, &y);
}

void	init_player_frames()
{
	
}
