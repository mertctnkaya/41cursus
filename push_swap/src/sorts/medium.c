/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 22:32:19 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/03 20:49:57 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_3(t_node **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->index;
	mid = (*a)->next->index;
	bot = (*a)->next->next->index;
	if (top < mid && mid > bot && top < bot)
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if (top > mid && mid < bot && top < bot)
		sa(a, 1);
	else if (top < mid && mid > bot && top > bot)
		rra(a, 1);
	else if (top > mid && mid < bot && top > bot)
		ra(a, 1);
	else if (top > mid && mid > bot)
	{
		sa(a, 1);
		rra(a, 1);
	}
}

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

void	sort_5(t_stack *s)
{
	int	i;

	i = 0;
	while (s->size_a > 3)
	{
		bring_to_top(&s->a, i++, s->size_a);
		pb(s, 1);
	}
	sort_3(&s->a);
	while (i--)
		pa(s, 1);
}
