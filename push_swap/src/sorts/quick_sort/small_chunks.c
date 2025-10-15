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

void	sort_small_a(t_stack *s, int size)
{
	int	top;
	int	mid;
	int	bot;

	if (size <= 1 || is_sorted(s->a))
		return ;
	if (size == 2)
	{
		if (s->a->index > s->a->next->index)
			sa(&s->a, 1);
		return ;
	}
	top = s->a->index;
	mid = s->a->next->index;
	bot = s->a->next->next->index;
	if (top < mid && mid > bot && top < bot)
	{
		rra(&s->a, 1);
		sa(&s->a, 1);
	}
	else if (top > mid && mid < bot && top < bot)
		sa(&s->a, 1);
	else if (top < mid && mid > bot && top > bot)
		rra(&s->a, 1);
	else if (top > mid && mid < bot && top > bot)
		ra(&s->a, 1);
	else if (top > mid && mid > bot)
	{
		sa(&s->a, 1);
		rra(&s->a, 1);
	}
}

void	sort_small_b(t_stack *s, int size)
{
	if (size == 0)
		return ;
	if (size == 1)
	{
		pa(&s->a, &s->b, 1);
		s->size_a++;
		s->size_b--;
		return ;
	}
	if (size == 2)
	{
		if (s->b && s->b->next && s->b->index < s->b->next->index)
			sb(&s->b, 1);
		pa(&s->a, &s->b, 1);
		pa(&s->a, &s->b, 1);
		s->size_a += 2;
		s->size_b -= 2;
		return ;
	}
	sort_small_b_three(s);
}

void	sort_small_b_three(t_stack *s)
{
	if (s->b->index >= s->b->next->index && s->b->index >= s->b->next->next->index)
	{
		pa(&s->a, &s->b, 1);
		s->size_a++;
		s->size_b--;
	}
	else if (s->b->next->index >= s->b->index && s->b->next->index >= s->b->next->next->index)
	{
		sb(&s->b, 1);
		pa(&s->a, &s->b, 1);
		s->size_a++;
		s->size_b--;
	}
	else
	{
		rb(&s->b, 1);
		sb(&s->b, 1);
		pa(&s->a, &s->b, 1);
		s->size_a++;
		s->size_b--;
		rrb(&s->b, 1);
	}
	if (s->b && s->b->next && s->b->index < s->b->next->index)
		sb(&s->b, 1);
	pa(&s->a, &s->b, 1);
	pa(&s->a, &s->b, 1);
	s->size_a += 2;
	s->size_b -= 2;
}
