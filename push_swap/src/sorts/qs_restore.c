/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_restore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:57:12 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/19 20:09:15 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void rotate_b_to_top(t_stack *s, int pos)
{
	int moves;

	if (pos <= s->size_b / 2)
	{
		while (pos-- > 0)
			rb(&s->b, 1);
	}
	else
	{
		moves = s->size_b - pos;
		while (moves-- > 0)
			rrb(&s->b, 1);
	}
}

void restore_sorted_from_b(t_stack *s)
{
	int pos;
	int min_pos;

	while (s->size_b > 0)
	{
		pos = find_min_pos(s->b);
		rotate_b_to_top(s, pos);
		pa(s, 1);
		ra(&s->a, 1);
	}
	if (is_sorted(s->a))
		return;
	min_pos = find_min_pos(s->a);
	if (min_pos <= s->size_a / 2)
	{
		while (min_pos-- > 0)
			ra(&s->a, 1);
	}
	else
	{
		while (min_pos++ < s->size_a)
			rra(&s->a, 1);
	}
}

void restore_by_max(t_stack *s)
{
	int pos;

	while (s->size_b > 0)
	{
		pos = find_max_pos(s->b); 
		rotate_b_to_top(s, pos);
		pa(s, 1); // size b her pa ile azalır
	}
	if (!is_sorted(s->a))
		restore_final_sort(s);
}

void restore_final_sort(t_stack *s)
{
	int min_pos;

	min_pos = find_min_pos(s->a);
	if (min_pos <= s->size_a / 2)
	{
		while (min_pos-- > 0)
			ra(&s->a, 1);
	}
	else
	{
		min_pos = s->size_a - min_pos;
		while (min_pos-- > 0)
			rra(&s->a, 1);
	}
}
