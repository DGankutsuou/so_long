/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:46:05 by aabouriz          #+#    #+#             */
/*   Updated: 2025/01/14 18:40:45 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	limit_checker(long value)
{
	if (value > (long)2147483647 || value < (long)-2147483648)
		return (1);
	return (0);
}
