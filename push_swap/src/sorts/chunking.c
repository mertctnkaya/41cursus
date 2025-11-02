/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:09:52 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/02 18:39:25 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
	restore_by_max(s);
}
