/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:39:22 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/27 09:10:25 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft/libft.h"
# include "minilibx_linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/X.h>

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
	int		exit_counter;
}	t_map;

typedef struct s_things
{
	void	*wall;
	void	*ground;
	void	*clct;
	void	*ply;
	void	*exit;
}	t_things;

typedef struct s_anime
{
	char	*mainp[4];
	char	*clc[2];
}	t_anime;

typedef struct s_hook
{
	t_map		*minf;
	t_things	*thing;
	t_anime		*anime;
	void		*mlx;
	void		*win;
	int			counter;
	int			fram;
	int			sleeper;
}	t_hook;

void	elements_validator(t_map *map_inf);
void	map_validator(char *map, t_map *map_in);
void	error(char *msg, int stat);
void	free_map(char **map);
void	game_starter(t_map *minf, t_things *thing);
void	up(t_hook *hook);
void	right(t_hook *hook);
void	left(t_hook *hook);
void	down(t_hook *hook);
void	distroyer(t_hook *hook);

#endif
