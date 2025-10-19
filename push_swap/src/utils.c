/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 23:11:18 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/17 19:48:47 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void raise_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int is_sorted(t_item *stack)
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

long atol_check(const char *str)
{
	long res;
	int sign;

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

int match_case(t_item *a, int *n)
{
	// Stack'in ilk dört elemanının belirli bir sıraya uyup uymadığını kontrol eder.
	return (a->index == n[0] && a->next->index == n[1] && a->next->next->index == n[2] && a->next->next->next->index == n[3]);
}

int do_operations(t_stack *s, int op)
{
	// Bitwise işlemlerle birden fazla operasyonu aynı anda uygular.
	if (op & 1)
		sa(&s->a, 1); // Swap işlemi.
	if (op & 2)
		ra(&s->a, 1); // Rotate işlemi.
	if (op & 4)
		rra(&s->a, 1); // Reverse rotate işlemi.
	if (op & 8)
	{
		sa(&s->a, 1);
		rra(&s->a, 1);
		sa(&s->a, 1);
	}
	return (1);
}
