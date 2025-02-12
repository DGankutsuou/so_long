/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:21:12 by aabouriz          #+#    #+#             */
/*   Updated: 2025/02/08 19:35:00 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
void	fill_storage(int fd, char **storage);
char	*get_line(char **storage);
size_t	ft_strlen_get(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	get_line_len(char *str);
size_t	ft_strlcpy_get(char *dst, const char *src, size_t size);
char	*ft_strjoin_and_free(char const *s1, char const *s2);
#endif
