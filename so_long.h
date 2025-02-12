/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:39:22 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/12 18:27:06 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_map
{
	int		rows;
	int		coloms;
	char	**grid;
}	t_map;

void	map_validator(char *map, t_map *map_in);
void	error(char *msg, int stat);
void	free_map(char **map);

#endif