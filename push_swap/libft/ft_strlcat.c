/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:42:05 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/02 18:21:41 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	cpylen;
	size_t	dstlen;

	i = 0;
	srclen = 0;
	dstlen = 0;
	while (src[srclen])
		srclen++;
	while (dst[dstlen])
		dstlen++;
	if (dstlen >= size)
		return (size + srclen);
	cpylen = size - dstlen - 1;
	while (src[i] && i < cpylen)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = 0;
	return (dstlen + srclen);
}
