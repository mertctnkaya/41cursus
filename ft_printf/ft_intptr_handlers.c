/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intptr_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:04:07 by mecetink          #+#    #+#             */
/*   Updated: 2025/07/02 17:22:58 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

ssize_t	handle_int(va_list args)
{
	char	*str;
	ssize_t	written;

	str = ft__itoa((int)va_arg(args, int));
	if (!str)
		return (-1);
	written = ft__putstr(str);
	free(str);
	return (written);
}

ssize_t	handle_uint(va_list args)
{
	unsigned int	num;
	char			*str;
	ssize_t			written;

	num = (unsigned int)va_arg(args, unsigned int);
	str = ft_utoa_base(num, "0123456789");
	if (!str)
		return (-1);
	written = ft__putstr(str);
	free(str);
	return (written);
}

ssize_t	handle_hex(va_list args, int type)
{
	unsigned int	num;
	char			*str;
	ssize_t			written;

	num = (unsigned int)va_arg(args, unsigned int);
	if (type == 'x')
		str = ft_utoa_base(num, "0123456789abcdef");
	else
		str = ft_utoa_base(num, "0123456789ABCDEF");
	if (!str)
		return (-1);
	written = ft__putstr(str);
	free(str);
	return (written);
}

ssize_t	handle_ptr(va_list args)
{
	unsigned long	ptr;
	char			*str;
	ssize_t			written0x;
	ssize_t			written;

	ptr = (unsigned long)va_arg(args, void *);
	if (ptr == 0)
		return (ft__putstr("(nil)"));
	str = ft_utoa_base(ptr, "0123456789abcdef");
	if (!str)
		return (-1);
	written0x = ft__putstr("0x");
	written = ft__putstr(str);
	free(str);
	if (written0x == -1 || written == -1)
		return (-1);
	return (written0x + written);
}
