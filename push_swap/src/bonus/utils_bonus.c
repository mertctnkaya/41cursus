/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:48:06 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/06 03:24:46 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker_bonus.h"

void	raise_error(t_node *a, t_node *b, char **split_arr)
{
	int	i;

	write(2, "Error\n", 6);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (split_arr)
	{
		i = 0;
		while (split_arr[i])
		{
			free(split_arr[i]);
			i++;
		}
		free(split_arr);
	}
	exit(1);
}

int	is_sorted(t_node *node)
{
	if (!node)
		return (1);
	while (node->next)
	{
		if (node->index > node->next->index)
			return (0);
		node = node->next;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	a;
	unsigned char	b;

	while (*s1 || *s2)
	{
		a = (unsigned char)*s1;
		b = (unsigned char)*s2;
		if (a != b)
			return (a - b);
		s1++;
		s2++;
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

long	atol_check(const char *str, t_node *a, char **split_arr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!(*str >= 48 && *str <= 57))
		raise_error(a, 0, split_arr);
	while ((*str >= 48 && *str <= 57))
	{
		res = res * 10 + (*str - '0');
		if ((unsigned long)res > (unsigned long)2147483647 + (sign < 0))
			raise_error(a, 0, split_arr);
		str++;
	}
	if (*str != '\0')
		raise_error(a, 0, split_arr);
	return (res * sign);
}
