/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:44:17 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/07 22:32:06 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void rra(t_item **a, int cout)
{
	t_item *head;
	t_item *tail;

	if (!*a || !(*a)->next)
		return;
	head = *a;
	tail = *a;
	while (tail->next)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	head->prev = tail;
	*a = tail;
	if (cout)
		write(1, "rra\n", 4);
}

void rrb(t_item **b, int cout)
{
	t_item *head;
	t_item *tail;

	if (!*b || !(*b)->next)
		return;
	head = *b;
	tail = *b;
	while (tail->next)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	head->prev = tail;
	*b = tail;
	if (cout)
		write(1, "rrb\n", 4);
}

void rrr(t_item **a, t_item **b, int cout)
{
	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return;
	rra(a, 0);
	rrb(b, 0);
	if (cout)
		write(1, "rrr\n", 4);
}
