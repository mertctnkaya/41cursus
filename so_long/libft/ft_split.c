/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:26:32 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/16 15:38:31 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	count_words(const char *s, char c, int push, char **arr)
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
			if (push && arr)
				arr[words++] = ft_substr(s + i, 0, word_len);
			else
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
		return (0);
	words = count_words(s, c, 0, 0);
	arr = (char **)malloc((sizeof(char *) * (words + 1)));
	if (!arr)
		return (0);
	words = count_words(s, c, 1, arr);
	arr[words] = 0;
	return (arr);
}
