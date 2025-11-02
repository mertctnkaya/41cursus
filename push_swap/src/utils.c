/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 23:11:18 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/02 16:12:27 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

long	atol_check(const char *str, t_node *a)
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
		raise_error(a, 0);
	while ((*str >= 48 && *str <= 57))
	{
		res = res * 10 + (*str - '0');
		if (res > 2147483647 + (sign < 0))
			raise_error(a, 0);
		str++;
	}
	if (*str != '\0')
		raise_error(a, 0);
	return (res * sign);
}

int	match_case(t_node *a, int *n)
{
	return (a->index == n[0] && a->next->index == n[1]
		&& a->next->next->index == n[2] && a->next->next->next->index == n[3]);
}

int	do_operations(t_stack *s, int op)
{
	if (op & 1)
		sa(&s->a, 1);
	if (op & 2)
		ra(&s->a, 1);
	if (op & 4)
		rra(&s->a, 1);
	if (op & 8)
	{
		sa(&s->a, 1);
		rra(&s->a, 1);
		sa(&s->a, 1);
	}
	return (1);
}
