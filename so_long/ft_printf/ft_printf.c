/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:58:51 by mecetink          #+#    #+#             */
/*   Updated: 2025/07/04 17:48:50 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	handle_formatters(va_list args, int type)
{
	if (type == 'c')
		return (handle_char(args));
	else if (type == 's')
		return (handle_str(args));
	else if (type == '%')
		return (handle_percent());
	else if (type == 'd' || type == 'i')
		return (handle_int(args));
	else if (type == 'u')
		return (handle_uint(args));
	else if (type == 'x' || type == 'X')
		return (handle_hex(args, type));
	else if (type == 'p')
		return (handle_ptr(args));
	else
	{
		write(1, "%", 1);
		write(1, &type, 1);
		return (2);
	}
}

static ssize_t	h_error(const char *fmt, ssize_t wrtn, int *count, va_list args)
{
	if (!fmt)
	{
		*count = -1;
		return (-1);
	}
	if (wrtn == -1)
	{
		if (args)
			va_end(args);
		return (-1);
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	ssize_t	written;
	int		count;

	count = 0;
	written = 0;
	h_error(fmt, written, &count, NULL);
	va_start(args, fmt);
	while (fmt && *fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
			written = handle_formatters(args, *(fmt + 1));
		else
			written = write(1, fmt, 1);
		if (h_error(fmt, written, &count, args) == -1)
			return (-1);
		count += (int)written;
		if (*fmt == '%' && *(fmt + 1))
			fmt += 2;
		else
			fmt++;
	}
	va_end(args);
	return (count);
}
