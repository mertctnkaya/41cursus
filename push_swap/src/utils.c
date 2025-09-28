/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 23:11:18 by mecetink          #+#    #+#             */
/*   Updated: 2025/09/29 01:36:41 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	raise_error()
{
	write(1, "Error\n", 6);
	exit(1);
}

int	is_sorted(t_item *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

long	ft_atol_check(const char *str)
{
	long res;
	int sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!(*str >= 48 && *str <= 57))
		raise_error();
	while ((*str >= 48 && *str <= 57))
	{
		res = res * 10 + (*str - '0');
		if ((sign == 1 && res > 2147483647) || (sign == -1 && res > 2147483648))
			raise_error();
		str++;
	}
	if (*str != '\0')
		raise_error();
	return (res * sign);
}

int	match_case(t_item *a, int i0, int i1, int i2, int i3)
{
	return (a->index == i0 && a->next->index == i1
		&& a->next->next->index == i2
		&& a->next->next->next->index == i3);
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
		ra(&s->a, 1);
		ra(&s->a, 1);
	}
	return (1);
}
