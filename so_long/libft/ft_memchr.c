/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:15:30 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/04 22:56:44 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*usrc;
	unsigned char		uchar;

	usrc = (unsigned char *)s;
	uchar = (unsigned char)c;
	while (n--)
	{
		if (*usrc == uchar)
			return ((void *)usrc);
		usrc++;
	}
	return (NULL);
}
