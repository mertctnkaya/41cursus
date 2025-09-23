/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_alg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:52:49 by mecetink          #+#    #+#             */
/*   Updated: 2025/09/23 14:30:02 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 2 elemanlı yığını en fazla 1 işlemle sıralar.
void sort_2(t_node **a)
{
	if (!is_sorted(*a))
		sa(a, 1);
}

// 3 elemanlı yığını en fazla 2 işlemle sıralar (Hardcoded Logic).
void sort_3(t_node **a)
{
	int top;
	int mid;

	if (is_sorted(*a))
		return;

	top = (*a)->index;
	mid = (*a)->next->index;

	if (top == 0 && mid == 2) // Durum: 0 2 1
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if (top == 1 && mid == 0) // Durum: 1 0 2
		sa(a, 1);
	else if (top == 1 && mid == 2) // Durum: 1 2 0
		rra(a, 1);
	else if (top == 2 && mid == 0) // Durum: 2 0 1
		ra(a, 1);
	else if (top == 2 && mid == 1) // Durum: 2 1 0
	{
		sa(a, 1);
		rra(a, 1);
	}
}
