/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:18:49 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/27 20:28:24 by aabouriz         ###   ########.fr       */
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

void	init_player_frames(t_anime *anime)
{
	anime->is_player_mv = 0;
	anime->mainp[0] = "textures/front_char1.xpm";
	anime->mainp[1] = "textures/front_char2.xpm";
	anime->mainp[2] = "textures/front_char3.xpm";
	anime->mainp[3] = "textures/front_char4.xpm";
	anime->player_r[0] = "textures/character_right_mv1.xpm";
	anime->player_r[1] = "textures/character_right_mv2.xpm";
	anime->player_r[2] = "textures/character_right_mv3.xpm";
	anime->player_r[3] = "textures/character_right_mv4.xpm";
	anime->player_r[4] = "textures/character_right_mv5.xpm";
}

void	init_clct_frames(t_anime *anime)
{
	anime->clc[0] = "textures/collect1.xpm";
	anime->clc[1] = "textures/collect2.xpm";
	anime->is_clct_mv = 0;
}
