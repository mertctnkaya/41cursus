/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:48:06 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/28 13:06:48 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	a;
	unsigned char	b;

	while (*s1 || *s2)
	{
		a = (unsigned char)*s1;
		b = (unsigned char)*s2;
		if (a != b)
			return (a - b);
		s1++;
		s2++;
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
