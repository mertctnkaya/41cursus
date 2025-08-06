/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:59:34 by mecetink          #+#    #+#             */
/*   Updated: 2025/08/06 14:37:00 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	write_pid(int pid)
{
	if (pid >= 10)
		write_pid(pid / 10);
	write(1, &((char []){'0' + (pid % 10)}), 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_atoi(const char *str)
{
	int	result;

	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (result);
}
