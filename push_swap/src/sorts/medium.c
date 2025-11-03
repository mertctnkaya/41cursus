/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 22:32:19 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/03 14:29:55 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	bring_to_top(t_node **a, int index, int size_a)
{
	int		pos;
	t_node	*temp;

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
		pos = size_a - pos;
		while (pos-- > 0)
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
		return (do_operations(s, 2 | 4));
	return (0);
}

void	sort_4(t_stack *s)
{
	if (check_special_4(s))
		return ;
	bring_to_top(&s->a, 0, s->size_a);
	if (is_sorted(s->a))
		return ;
	pb(s, 1);
	sort_3(&s->a);
	pa(s, 1);
}

static void	push_smallest_two(t_stack *s)
{
	bring_to_top(&s->a, 0, s->size_a);
	pb(s, 1);
	bring_to_top(&s->a, 1, s->size_a);
	pb(s, 1);
}

void	sort_5(t_stack *s)
{
	push_smallest_two(s);
	sort_3(&s->a);
	if (s->b->index < s->b->next->index)
		sb(&s->b, 1);
	pa(s, 1);
	pa(s, 1);
}
