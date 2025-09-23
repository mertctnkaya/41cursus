/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:43:26 by mecetink          #+#    #+#             */
/*   Updated: 2025/09/22 21:17:17 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// sa (swap a): Yığın a'nın ilk 2 elemanını değiştirir.
void sa(t_node **a, int print)
{
	int temp_value;
	int temp_index;

	if (!*a || !(*a)->next)
		return;
	temp_value = (*a)->value;
	temp_index = (*a)->index;
	(*a)->value = (*a)->next->value;
	(*a)->index = (*a)->next->index;
	(*a)->next->value = temp_value;
	(*a)->next->index = temp_index;
	if (print)
		write(1, "sa\n", 3);
}

// sb (swap b): Yığın b'nin ilk 2 elemanını değiştirir.
void sb(t_node **b, int print)
{
	int temp_value;
	int temp_index;

	if (!*b || !(*b)->next)
		return;
	temp_value = (*b)->value;
	temp_index = (*b)->index;
	(*b)->value = (*b)->next->value;
	(*b)->index = (*b)->next->index;
	(*b)->next->value = temp_value;
	(*b)->next->index = temp_index;
	if (print)
		write(1, "sb\n", 3);
}

// ss: sa ve sb'yi aynı anda yapar.
void ss(t_node **a, t_node **b, int print)
{
	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return;
	sa(a, 0);
	sb(b, 0);
	if (print)
		write(1, "ss\n", 3);
}
