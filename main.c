/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:57:05 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/14 15:15:54 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map_inf;

	if (argc != 2)
		error("Error: didn't recieve map", 1);
	map_validator(argv[1], &map_inf);
	game_starter();
	return (0);
}
