/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:39:22 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/11 16:39:23 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_map_d
{
	int	rows;
	int	coloms;
}	t_map_d;

void	map_validator(char *map, t_map_d *map_d);
void	error(char *msg, int stat);

#endif