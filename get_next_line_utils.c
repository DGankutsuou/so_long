/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:21:15 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/08 19:34:39 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_get(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen_get(s1);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy_get(ptr, s1, len + 1);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ptr;

	if (!s)
		return (NULL);
	s_len = ft_strlen_get (s);
	if (start >= s_len)
		return (ft_strdup (""));
	if (len > s_len - start)
		len = s_len - start;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy_get(ptr, &(s[start]), len + 1);
	return (ptr);
}

size_t	ft_strlcpy_get(char *dst, const char *src, size_t size)
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
	return (ft_strlen_get(src));
}
