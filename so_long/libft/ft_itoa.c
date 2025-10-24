/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:51:14 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/16 14:44:16 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	countdigit(long n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		is_negative;
	long	num;

	num = n;
	is_negative = (num < 0);
	if (is_negative)
		num = -num;
	len = countdigit(num) + is_negative;
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len--] = 0;
	if (is_negative)
		ret[0] = '-';
	if (n == 0)
		ret[0] = '0';
	while (num != 0)
	{
		ret[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (ret);
}
