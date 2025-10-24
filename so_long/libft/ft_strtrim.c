/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:44:07 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/17 00:48:49 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	setlength;
	size_t	start;
	char	*newstr;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*s1 == 0)
	{
		newstr = ((char *) malloc(sizeof(char)));
		if (newstr)
			*newstr = 0;
		return (newstr);
	}
	setlength = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (setlength > start && ft_strchr(set, s1[setlength - 1]))
		setlength--;
	newstr = (char *) malloc(sizeof(char) * (setlength - start + 1));
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, s1 + start, setlength - start);
	newstr[setlength - start] = 0;
	return (newstr);
}
