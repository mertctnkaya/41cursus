/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:09:52 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/10 14:50:06 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	sort_small(t_stack *s)
{
	if (s->size_a == 2)
		sort_2(&s->a);
	else if (s->size_a == 3)
		sort_3(&s->a);
	else if (s->size_a == 4)
		sort_4(s);
	else if (s->size_a == 5)
		sort_5(s);
}

/* quick_partition.c */

void	partition(t_stack *s, int pivot, int size)
{
	int	i;
	int	threshold;

	/* threshold ile çok küçükleri B'nin altına gönder */
	threshold = pivot - (size / 4); /* heuristic: pivot-12.5% */
	i = 0;
	while (i < size)
	{
		if (s->a->index <= pivot)
		{
			pb(&s->a, &s->b, 1);
			s->size_a--;
			s->size_b++;
			/* eğer yeni üst elemana göre çok küçükse, rb ile aşağı at */
			if (s->b && s->b->index <= threshold)
				rb(&s->b, 1);
		}
		else
			ra(&s->a, 1);
		i++;
	}
}


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

void	restore_sorted_from_b(t_stack *s)
{
	int	pos;
	int	min_pos;

	while (s->size_b > 0)
	{
		pos = find_min_pos(s->b);
		rotate_b_to_top(s, pos);
		pa(&s->a, &s->b, 1);
		s->size_a++;
		s->size_b--;
		ra(&s->a, 1);
	}
	if (is_sorted(s->a))
		return ;
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

int	find_max_pos(t_item *stack)
{
	int	pos;
	int	max_pos;
	int	max;
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

void	restore_by_max(t_stack *s)
{
	int	pos;

	while (s->size_b > 0)
	{
		pos = find_max_pos(s->b);
		rotate_b_to_top(s, pos);
		pa(&s->a, &s->b, 1);
		s->size_a++;
		s->size_b--;
	}
	if (!is_sorted(s->a))
	{
		int min_pos = find_min_pos(s->a);
		if (min_pos <= s->size_a / 2)
			while (min_pos-- > 0)
				ra(&s->a, 1);
		else
		{
			min_pos = s->size_a - min_pos;
			while (min_pos-- > 0)
				rra(&s->a, 1);
		}
	}
}

void	quick_sort(t_stack *s)
{
	int	pivot;
	int	size;

	if (is_sorted(s->a))
		return ;
	if (s->size_a <= 5)
	{
		sort_small(s);
		return ;
	}
	size = s->size_a;
	pivot = get_pivot(s->a, size);
	partition(s, pivot, size);
	quick_sort(s);
	restore_by_max(s);
}
