/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_partition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:57:12 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/14 23:57:12 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	partition(t_stack *s, int pivot, int size)
{
	int	i;
	int	threshold;
	int	rotated;

	threshold = pivot - (size / 4);
	i = 0;
	rotated = 0;
	while (i < size)
	{
		if (s->a->index <= pivot)
		{
			pb(&s->a, &s->b, 1);
			s->size_a--;
			s->size_b++;
			if (s->b && s->b->index <= threshold)
				rb(&s->b, 1);
		}
		else
		{
			ra(&s->a, 1);
			rotated++;
		}
		i++;
	}
	while (rotated-- > 0)
		rra(&s->a, 1);
}

void	partition_a_to_b(t_stack *s, int pivot, int size, int *pushed_to_b)
{
	int	i;
	int	rotated;
	int	threshold;

	threshold = pivot - (size / 4);
	i = 0;
	rotated = 0;
	*pushed_to_b = 0;
	while (i < size)
	{
		if (s->a->index <= pivot)
		{
			pb(&s->a, &s->b, 1);
			s->size_a--;
			s->size_b++;
			(*pushed_to_b)++;
			if (s->b && s->b->index <= threshold)
				rb(&s->b, 1);
		}
		else
		{
			ra(&s->a, 1);
			rotated++;
		}
		i++;
	}
	while (rotated-- > 0)
		rra(&s->a, 1);
}

void	partition_b_to_a(t_stack *s, int pivot, int size, int *pushed_to_a)
{
	int	i;
	int	rotated;

	i = 0;
	rotated = 0;
	*pushed_to_a = 0;
	while (i < size)
	{
		if (s->b->index > pivot)
		{
			pa(&s->a, &s->b, 1);
			s->size_a++;
			s->size_b--;
			(*pushed_to_a)++;
		}
		else
		{
			rb(&s->b, 1);
			rotated++;
		}
		i++;
	}
	while (rotated-- > 0)
		rrb(&s->b, 1);
}
