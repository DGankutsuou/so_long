/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:39:22 by aabouriz          #+#    #+#             */
/*   Updated: 2025/03/01 18:47:00 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/X.h>

# define U 119
# define R 100
# define L 97
# define D 115

# define SPEED 4

typedef struct s_map
{
	int		rows;
	int		coloms;
	char	**grid;
	char	**grid_copy;
	int		p_xy[2];
	int		e_xy[2];
	int		collectees;
	int		player_counter;
	int		fire_counter;
	int		exit_counter;
}	t_map;

typedef struct s_things
{
	void	*wall;
	void	*grd;
	void	*clct;
	void	*ply;
	void	*exit;
	void	*fire;
}	t_things;

typedef struct s_anime
{
	int		is_player_mv;
	int		is_clct_mv;
	int		is_zombie_mv;
	char	player_mv;
	char	clct_mv;
	char	zombie_mv;
	char	*mainp[4];
	char	*player_f[5];
	char	*player_b[5];
	char	*player_l[5];
	char	*player_r[5];
	char	*clc[2];
	char	*firef[4];
}	t_anime;

typedef struct s_hook
{
	t_map		*minf;
	t_things	*thing;
	t_anime		*anime;
	void		*mlx;
	void		*win;
	int			counter;
	int			clct_frame;
	int			player_frame;
	int			fire_frame;
	int			clct_sleeper;
	int			player_sleeper;
	int			player_mv_sleeper;
	int			fire_sleeper;
}	t_hook;

typedef struct s_move
{
	int			x;
	int			y;
	int			a;
	int			b;
	char		*pf;
}	t_move;

void	elements_validator(t_map *map_inf);
void	map_validator(char *map, t_map *map_in);
void	enemy_puter(t_map *minf);
void	error(char *msg, int stat);
void	free_map(char **map);

void	init_things(t_things *thing, void *mlx);
void	init_player_frames(t_anime *anime);
void	init_clct_frames(t_anime *anime);
void	init_hook(t_hook *hook);
void	init_enemy(t_anime *anime);

void	draw_all_things(t_map *minf, t_things *thing, void *mlx, void *win);
void	draw_clct(t_hook *hook);
void	draw_player(t_hook *hook);
void	draw_things(t_hook *hook);
void	draw_fire(t_hook *hook);

void	game_starter(t_map *minf, t_things *thing);

void	move_player(t_hook *hook);
void	clct_scared(t_hook *hook);
void	player_breath(t_hook *hook);
void	fire_animation(t_hook *hook);

void	up(t_hook *hook);
void	right(t_hook *hook);
void	left(t_hook *hook);
void	down(t_hook *hook);
void	arive_l(t_hook *hook, int *idx, int *growth);
void	arive_r(t_hook *hook, int *idx, int *growth);
void	arive_u(t_hook *hook, int *idx, int *growth);
void	arive_d(t_hook *hook, int *idx, int *growth);
void	distroyer(t_hook *hook);

#endif
