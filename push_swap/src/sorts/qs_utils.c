/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:06:54 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/21 18:40:44 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void rotate_b_to_top(t_stack *s, int pos)
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

static int find_min_pos(t_item *stack)
{
	int		min;
	int		pos;
	int		min_pos;
	t_item	*cur;

	if (!stack)
		return (0);
	cur = stack;
	min = cur->index;
	min_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->index < min)
		{
			min = cur->index;
			min_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (min_pos);
}

static int find_max_pos(t_item *stack)
{
	int pos;
	int max_pos;
	int max;
	t_item *cur;

	if (!stack)
		return (0);
	cur = stack;
	max = cur->index;
	max_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
			max_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (max_pos);
}

void restore_by_max(t_stack *s)
{
	int pos;

	while (s->size_b > 0)
	{
		pos = find_max_pos(s->b); 
		rotate_b_to_top(s, pos);
		pa(s, 1);
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
