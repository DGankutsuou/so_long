/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:35:44 by aabouriz          #+#    #+#             */
/*   Updated: 2025/03/01 17:28:26 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len + 1);
	return (ptr);
}

static int	number_len(int n)
{
	int	number_len;

	number_len = 1;
	if (n < 0)
		number_len = 2;
	while (n / 10)
	{
		n /= 10;
		number_len++;
	}
	return (number_len);
}

char	*ft_itoa(int n)
{
	int		n_len;
	char	*number;
	int		first_index;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_len = number_len(n);
	number = (char *)malloc(n_len + 1);
	if (!number)
		return (NULL);
	first_index = 0;
	if (n < 0)
	{
		n *= -1;
		number[0] = '-';
		first_index++;
	}
	number[n_len--] = '\0';
	while (n_len >= first_index)
	{
		number[n_len] = n % 10 + '0';
		n /= 10;
		n_len--;
	}
	return (number);
}
