/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:58:51 by mecetink          #+#    #+#             */
/*   Updated: 2025/07/21 17:13:25 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_printf.c
 * @brief Implementation of the ft_printf function.
 * This function is a custom implementation of the printf function,
 * which formats and outputs data to the standard output.
 * It supports various format specifiers for different data types.
 * @note This function uses variadic arguments to handle different types of data.
 * It processes format specifiers and calls appropriate handler functions for each type.
 * * It returns the total number of characters printed.
 * * It handles format specifiers such as %c, %s, %d, %i, %u, %x, %X, and %p.
 * It also handles the % character itself.
 * @return int The total number of characters printed, or -1 if an error occurs.
 * @note This function assumes that the format string is valid and does not contain any unsupported format specifiers.
 * @note This function handles some of the undefined behaviors of the standard printf function, such as
 *       handling NULL pointers and invalid format specifiers.
 */

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

/**
 * @brief Handles errors and returns appropriate values.
 * This function checks for NULL format strings and handles write errors.
 * It also manages the end of variadic arguments if necessary.
 * Purpose is to reduce code duplication due to Norm and improve readability.
 * @param fmt The format string to be processed.
 * @param wrtn The number of bytes written.
 * @param count Pointer to the total count of characters printed.
 * @param args The variadic arguments list.
 * @return ssize_t Returns -1 on error, or 0 on success.
 */
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
