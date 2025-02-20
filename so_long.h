/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blessed <blessed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:39:22 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/18 14:41:17 by blessed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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

void	elements_validator(t_map *map_inf);
void	map_validator(char *map, t_map *map_in);
void	error(char *msg, int stat);
void	free_map(char **map);

#endif