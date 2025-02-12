/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:21:05 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/08 19:34:52 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_line_len(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	return (len);
}

char	*ft_strjoin_and_free(char const *s1, char const *s2)
{
	char	*join;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	s1_len = ft_strlen_get(s1);
	s2_len = ft_strlen_get(s2);
	join = (char *)malloc(s1_len + s2_len + 1);
	if (!join)
		return (NULL);
	ft_strlcpy_get(join, s1, s1_len + 1);
	i = 0;
	while (s2[i] && i < s2_len)
	{
		join[s1_len + i] = s2[i];
		i++;
	}
	join[s1_len + i] = '\0';
	free((char *)s1);
	free((char *)s2);
	return (join);
}

void	fill_storage(int fd, char **storage)
{
	char	*buffer;
	ssize_t	chars_read;

	chars_read = 1;
	while (!ft_strchr (*storage, '\n'))
	{
		buffer = (char *)malloc (BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		chars_read = read (fd, buffer, BUFFER_SIZE);
		if (chars_read <= 0)
		{
			free (buffer);
			return ;
		}
		buffer[chars_read] = '\0';
		*storage = ft_strjoin_and_free (*storage, buffer);
	}
}

char	*get_line(char **storage)
{
	char	*line;
	size_t	line_len;

	if (!*storage)
		return (NULL);
	line_len = get_line_len (*storage);
	if (line_len == 0)
	{
		free (*storage);
		*storage = NULL;
		return (NULL);
	}
	line = ft_substr (*storage, 0, line_len);
	if (*storage && !ft_strchr(*storage, '\n'))
	{
		free(*storage);
		return (*storage = NULL, line);
	}
	free (*storage);
	return (*storage = NULL, line);
}

char	*get_next_line(int fd)
{
	char	*storage;

	storage = NULL;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	fill_storage (fd, &storage);
	return (get_line (&storage));
}
/*
int	main(void)
{
	int fd = open ("f.txt", O_RDONLY);
	int fd2 = open ("fl.txt", O_RDONLY);
	char * line;
	for (int i = 0; i < 4; i++)
	{
		line = get_next_line(fd);
		printf ("-> %s\n", line);
		free (line);
	}
	for (int i = 0; i < 4; i++)
	{
		line = get_next_line(fd2);
		printf ("-> %s\n", line);
		free (line);
	}
	return (0);
}
*/
