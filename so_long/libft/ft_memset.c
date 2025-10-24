/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:47:22 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/03 20:39:17 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cast;
	unsigned char	val;

	cast = (unsigned char *)s;
	val = (unsigned char)c;
	while (n--)
		*cast++ = val;
	return (s);
}
