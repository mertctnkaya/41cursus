/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:07:04 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/16 15:38:15 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	int		s1len;
	int		s2len;
	int		i;

	i = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	newstr = (char *) malloc(sizeof(char) * (s1len + s2len + 1));
	if (!newstr)
		return (NULL);
	while (*s1)
	{
		newstr[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		newstr[i] = *s2;
		s2++;
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}
