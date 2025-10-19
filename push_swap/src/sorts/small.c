/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:52:49 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/17 19:50:12 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void sort_2(t_item **a)
{
	if (!is_sorted(*a))
		sa(a, 1);
}

void sort_3(t_item **a)
{
	int top;
	int mid;
	int bot;

	if (is_sorted(*a))
		return;
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
