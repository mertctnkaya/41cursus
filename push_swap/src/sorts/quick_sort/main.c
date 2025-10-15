/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:09:52 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/15 17:34:16 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	quick_sort_small(t_stack *s)
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

void	quick_sort_chunk(t_stack *s)
{
	int	target;
	int	chunk;

	if (is_sorted(s->a))
		return ;
	if (s->size_a <= 5)
	{
		quick_sort_small(s);
		return ;
	}
	chunk = (s->total_size <= 100) ? 15 : 30;
	target = 0;
	while (s->size_a > 0)
	{
		if (s->a->index <= target)
		{
			pb(&s->a, &s->b, 1);
			s->size_a--;
			s->size_b++;
			rb(&s->b, 1);
			target++;
		}
		else if (s->a->index <= target + chunk)
		{
			pb(&s->a, &s->b, 1);
			s->size_a--;
			s->size_b++;
			target++;
		}
		else
			ra(&s->a, 1);
	}
	restore_by_max(s);
}



void	quick_sort(t_stack *s)
{
	if (is_sorted(s->a))
		return ;
	quick_sort_chunk(s);
}