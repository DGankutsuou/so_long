/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:18:49 by aabouriz          #+#    #+#             */
/*   Updated: 2025/03/01 15:33:49 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_things(t_things *thing, void *mlx)
{
	int	x;
	int	y;

	thing->wall = NULL;
	thing->grd = NULL;
	thing->clct = NULL;
	thing->ply = NULL;
	thing->exit = NULL;
	thing->fire = NULL;
	thing->wall = mlx_xpm_file_to_image(mlx, "textures/Wall.xpm", &x, &y);
	thing->grd = mlx_xpm_file_to_image(mlx, "textures/background.xpm", &x, &y);
	thing->clct = mlx_xpm_file_to_image(mlx, "textures/collect1.xpm", &x, &y);
	thing->ply = mlx_xpm_file_to_image(mlx, "textures/front_char1.xpm", &x, &y);
	thing->exit = mlx_xpm_file_to_image(mlx, "textures/exit.xpm", &x, &y);
	thing->fire = mlx_xpm_file_to_image(mlx, "textures/fire1.xpm", &x, &y);
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
	anime->player_l[0] = "textures/character_left_mv1.xpm";
	anime->player_l[1] = "textures/character_left_mv2.xpm";
	anime->player_l[2] = "textures/character_left_mv3.xpm";
	anime->player_l[3] = "textures/character_left_mv4.xpm";
	anime->player_l[4] = "textures/character_left_mv5.xpm";
	anime->player_f[0] = "textures/front_char_mv1.xpm";
	anime->player_f[1] = "textures/front_char_mv2.xpm";
	anime->player_f[2] = "textures/front_char_mv3.xpm";
	anime->player_f[3] = "textures/front_char_mv4.xpm";
	anime->player_f[4] = "textures/front_char_mv5.xpm";
	anime->player_b[0] = "textures/back_char_mv1.xpm";
	anime->player_b[1] = "textures/back_char_mv2.xpm";
	anime->player_b[2] = "textures/back_char_mv3.xpm";
	anime->player_b[3] = "textures/back_char_mv4.xpm";
	anime->player_b[4] = "textures/back_char_mv5.xpm";
}

void	init_hook(t_hook *hook)
{
	hook->counter = 1;
	hook->clct_frame = 0;
	hook->clct_sleeper = 0;
	hook->player_frame = 0;
	hook->player_sleeper = 0;
	hook->player_mv_sleeper = 0;
	hook->fire_sleeper = 0;
	hook->anime->is_zombie_mv = 0;
}

void	init_clct_frames(t_anime *anime)
{
	anime->clc[0] = "textures/collect1.xpm";
	anime->clc[1] = "textures/collect2.xpm";
	anime->is_clct_mv = 0;
}

void	init_enemy()
{

}
