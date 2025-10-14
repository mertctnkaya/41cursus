/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 22:32:19 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/10 12:39:06 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	bring_to_top(t_item **a, int index, int size_a)
{
	int		pos;
	t_item	*temp;

	pos = 0;
	temp = *a;
	while (temp)
	{
		if (temp->index == index)
			break ;
		temp = temp->next;
		pos++;
	}
	if (pos <= size_a / 2)
	{
		while (pos-- > 0)
			ra(a, 1);
	}
	else
	{
		while (pos++ < size_a)
			rra(a, 1);
	}
}

static int	check_special_4(t_stack *s)
{
	if (match_case(s->a, (int []){3, 2, 0, 1}))
		return (do_operations(s, 8));
	if (match_case(s->a, (int []){0, 2, 3, 1}))
		return (do_operations(s, 4 | 1));
	if (match_case(s->a, (int []){0, 3, 1, 2}))
		return (do_operations(s, 1 | 2));
	if (match_case(s->a, (int []){3, 1, 2, 0}))
		return (do_operations(s, 4 | 1 | 2));
	return (0);
}

void	sort_4(t_stack *s)
{
	if (is_sorted(s->a))
		return ;
	if (check_special_4(s))
		return ;
	bring_to_top(&s->a, 0, s->size_a);
	if (is_sorted(s->a))
		return ;
	pb(&s->a, &s->b, 1);
	s->size_a--;
	s->size_b++;
	sort_3(&s->a);
	pa(&s->a, &s->b, 1);
	s->size_a++;
	s->size_b--;
}

static void	push_smallest_two(t_stack *s)
{
	bring_to_top(&s->a, 0, s->size_a);
	pb(&s->a, &s->b, 1);
	s->size_a--;
	s->size_b++;
	bring_to_top(&s->a, 1, s->size_a);
	pb(&s->a, &s->b, 1);
	s->size_a--;
	s->size_b++;
}

void	sort_5(t_stack *s)
{
	if (is_sorted(s->a))
		return ;
	push_smallest_two(s);
	sort_3(&s->a);
	if (s->b->index < s->b->next->index)
		sb(&s->b, 1);
	pa(&s->a, &s->b, 1);
	s->size_a++;
	s->size_b--;
	pa(&s->a, &s->b, 1);
	s->size_a++;
	s->size_b--;
}
