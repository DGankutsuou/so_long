/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:17:07 by aabouriz          #+#    #+#             */
/*   Updated: 2024/11/04 21:07:46 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
int	main(void)
{
	int	arr[2] = {1, 2};

	ft_strlcpy ((char *)arr, "Name\0ess", 9);
	printf ("%d\n", arr[0]);
	printf ("%d\n", arr[1]);
	ft_memcpy (arr, "N\0me\0ll", 8);
	printf ("%d\n", arr[0]);
	printf ("%d\n", arr[1]);
	return (0);
}
*/
