/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:21:55 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/17 01:02:41 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*f;

	f = s + ft_strlen(s);
	while (f >= s)
	{
		if (*f == (char)c)
			return ((char *)f);
		f--;
	}
	return (0);
}
