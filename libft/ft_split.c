/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:36:20 by aabouriz          #+#    #+#             */
/*   Updated: 2025/01/14 09:53:01 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	counter;
	size_t	index;

	counter = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] && s[index] == c)
			index++;
		if (s[index] && s[index] != c)
			counter++;
		while (s[index] && s[index] != c)
			index++;
	}
	return (counter);
}

static void	free_split(char **splt, size_t words_index)
{
	while (words_index > 0)
	{
		words_index--;
		free(splt[words_index]);
	}
	free(splt);
}

static char	*dup_word(char const *s, char c)
{
	char	*word;
	size_t	counter;

	counter = 0;
	while (s[counter] && s[counter] != c)
		counter++;
	word = (char *)malloc(counter + 1);
	if (!word)
		return (NULL);
	counter = 0;
	while (s[counter] && s[counter] != c)
	{
		word[counter] = s[counter];
		counter++;
	}
	word[counter] = '\0';
	return (word);
}

static char	**filler(char **splt, char const *s, char c, size_t words)
{
	size_t	words_index;

	words_index = 0;
	while (words_index < words)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			splt[words_index] = dup_word(s, c);
			if (!splt[words_index])
			{
				free_split(splt, words_index);
				return (NULL);
			}
			words_index++;
		}
		while (*s && *s != c)
			s++;
	}
	splt[words_index] = NULL;
	return (splt);
}

char	**ft_split(char const *s, char c)
{
	char	**splt;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	splt = (char **)malloc(sizeof(char *) * (words + 1));
	if (!splt)
		return (NULL);
	splt = filler(splt, s, c, words);
	return (splt);
}
