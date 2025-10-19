/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_small_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:57:12 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/14 23:57:12 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void sort_small_a(t_stack *s, int size)
{
	if (size <= 1 || is_sorted(s->a))
		return;
	if (size == 2)
	{
		sort_2(&s->a);
		return;
	}
	if (size == 3)
	{
		sort_3(&s->a);
		return;
	}
}

void sort_small_b(t_stack *s, int size)
{
	if (size == 0)
		return;
	if (size == 1)
	{
		pa(s, 1);
		return;
	}
	if (size == 2)
	{
		if (s->b && s->b->next && s->b->index < s->b->next->index)
			sb(&s->b, 1);
		pa(s, 1);
		pa(s, 1);
		return;
	}
	sort_small_b_three(s);
}

void sort_small_b_three(t_stack *s)
{
	if (s->b->index >= s->b->next->index && s->b->index >= s->b->next->next->index)
		pa(s, 1);
	else if (s->b->next->index >= s->b->index && s->b->next->index >= s->b->next->next->index)
	{
		sb(&s->b, 1);
		pa(s, 1);
	}
	else
	{
		rb(&s->b, 1);
		sb(&s->b, 1);
		pa(s, 1);
		rrb(&s->b, 1);
	}
	if (s->b && s->b->next && s->b->index < s->b->next->index)
		sb(&s->b, 1);
	pa(s, 1);
	pa(s, 1);
}
