/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:13:25 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/06 21:41:08 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft__strjoin(char *s1, const char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +1));
	if (!newstr)
		return ((void *)0);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		newstr[i++] = s2[j++];
	free(s1);
	newstr[i] = 0;
	return (newstr);
}
