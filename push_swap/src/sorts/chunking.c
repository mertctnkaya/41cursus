/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:09:52 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/03 20:38:11 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rotate_b_to_top(t_stack *s, int pos)
{
	int	moves;

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

static int	find_max_pos(t_node *node)
{
	int		pos;
	int		max_pos;
	int		max;
	t_node	*cur;

	cur = node;
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

static void	push_by_chunk(t_stack *s, int *target, int chunk)
{
	if (s->a->index <= *target)
	{
		pb(s, 1);
		rb(&s->b, 1);
		(*target)++;
	}
	else if (s->a->index <= *target + chunk)
	{
		pb(s, 1);
		(*target)++;
	}
	else
		ra(&s->a, 1);
}

void	chunking_sort(t_stack *s)
{
	int	target;
	int	chunk;

	if (s->total_size <= 100)
		chunk = 15;
	else
		chunk = 30;
	target = 0;
	while (s->size_a > 0)
		push_by_chunk(s, &target, chunk);
	while (s->size_b > 0)
	{
		rotate_b_to_top(s, find_max_pos(s->b));
		pa(s, 1);
	}
}
