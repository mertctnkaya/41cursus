/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 01:37:36 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/06 03:19:23 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	ft_strlen(const char *s)
{
	const char	*start;

	start = s;
	while (*s)
		s++;
	return (s - start);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	i;

	if (start >= (unsigned int)ft_strlen(s))
	{
		copy = (char *) malloc(sizeof(char));
		if (!copy)
			return (NULL);
		copy[0] = 0;
		return (copy);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	copy = (char *) malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	s = s + start;
	i = 0;
	while (i < len && s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

static int	add_word(char **arr, const char *s, int word_len, int index)
{
	char	*word;

	word = ft_substr(s, 0, word_len);
	if (!word)
	{
		while (index--)
			free(arr[index]);
		free(arr);
		return (0);
	}
	arr[index] = word;
	return (1);
}

static int	count_words(const char *s, char c, int push, char **arr)
{
	int	i;
	int	word_len;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		word_len = 0;
		while (s[i + word_len] && s[i + word_len] != c)
			word_len++;
		if (word_len > 0)
		{
			if (push && arr && !(add_word(arr, s + i, word_len, words)))
				return (-1);
			words++;
			i += word_len;
		}
	}
	return (words);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c, 0, 0);
	arr = (char **) malloc((sizeof(char *) * (words + 1)));
	if (!arr)
		return (NULL);
	words = count_words(s, c, 1, arr);
	if (words == -1)
		return (NULL);
	arr[words] = 0;
	return (arr);
}
