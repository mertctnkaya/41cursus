/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:52:49 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/07 22:32:31 by mecetink         ###   ########.fr       */
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
	if (top < mid && mid > bot && top < bot) // [0,2,1]
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if (top > mid && mid < bot && top < bot) // [1,0,2]
		sa(a, 1);
	else if (top < mid && mid > bot && top > bot) // [1,2,0]
		rra(a, 1);
	else if (top > mid && mid < bot && top > bot) // [2,0,1]
		ra(a, 1);
	else if (top > mid && mid > bot) // [2,1,0]
	{
		sa(a, 1);
		rra(a, 1);
	}
}
