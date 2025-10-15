/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_recursive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:57:12 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/14 23:57:12 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	quicksort_a(t_stack *s, int size)
{
	int	pivot;
	int	pushed;

	if (size <= 1 || is_sorted(s->a))
		return ;
	if (size <= 3)
		return (sort_small_a(s, size));
	pivot = get_pivot(s->a, size);
	partition_a_to_b(s, pivot, size, &pushed);
	quicksort_a(s, size - pushed);
	quicksort_b(s, pushed);
}

void	quicksort_b(t_stack *s, int size)
{
	int	pivot;
	int	pushed;

	if (size <= 0)
		return ;
	if (size <= 3)
		return (sort_small_b(s, size));
	pivot = get_pivot(s->b, size);
	partition_b_to_a(s, pivot, size, &pushed);
	quicksort_a(s, pushed);
	quicksort_b(s, size - pushed);
}
