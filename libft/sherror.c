/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sherror.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:56:05 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/12 10:55:12 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sherror(char *str, int stat)
{
	perror(str);
	exit(stat);
}
