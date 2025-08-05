/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:04:39 by mecetink          #+#    #+#             */
/*   Updated: 2025/07/02 17:22:07 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

ssize_t	ft__putstr(const char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft__strlen(s)));
}

static int	count_digit(long n)
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

char	*ft__itoa(int n)
{
	char	*ret;
	int		len;
	int		is_negative;
	long	num;

	num = n;
	is_negative = (num < 0);
	if (is_negative)
		num = -num;
	len = count_digit(num) + is_negative;
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

char	*ft__strdup(const char *s)
{
	int		len;
	int		i;
	char	*dup;

	len = 0;
	while (s[len])
		len++;
	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return ((void *)0);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_utoa_base(unsigned long num, const char *base)
{
	char	buffer[21];
	int		base_len;
	int		i;

	i = 20;
	base_len = ft__strlen(base);
	buffer[i--] = 0;
	if (num == 0)
		buffer[i--] = '0';
	while (num > 0)
	{
		buffer[i--] = base[num % base_len];
		num /= base_len;
	}
	return (ft__strdup(&buffer[i + 1]));
}
