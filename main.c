/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:57:05 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/11 16:27:38 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map_d	map_d;

	if (argc != 2)
		error("Error: didn't recieve map", 1);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber") != 0)
		error("Error: invalid map file", 1);
	map_validator(argv[1], &map_d);
	return (0);
}