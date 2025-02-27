/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:09:45 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/27 16:41:54 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_hook *hook)
{
	if (hook->anime->player_mv == 'U')
		up(hook);
	else if (hook->anime->player_mv == 'R')
		right(hook);
	else if (hook->anime->player_mv == 'L')
		left(hook);
	else if (hook->anime->player_mv == 'D')
		down(hook);
	hook->anime->is_player_mv = 0;
}
